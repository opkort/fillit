/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 23:16:06 by pgenesis          #+#    #+#             */
/*   Updated: 2020/01/23 18:50:34 by ihilmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*checkhist(char **p_n, char *hist)
{
	char *str;

	if ((*p_n = ft_strchr(hist, '\n')) != NULL)
	{
		str = ft_strsub(hist, 0, *p_n - hist);
		ft_strcpy(hist, ++(*p_n));
	}
	else
	{
		str = ft_strnew(ft_strlen(hist) + 1);
		ft_strcat(str, hist);
		ft_strclr(hist);
	}
	return (str);
}

t_tail		*newtail(const int fd)
{
	t_tail	*new;

	if (!(new = (t_tail *)ft_memalloc(sizeof(t_tail))))
		return (NULL);
	new->fd = fd;
	new->hist = ft_strnew(BUFF_SIZE);
	new->next = NULL;
	return (new);
}

int			get_line(const int fd, char **line, char *hist)
{
	char			buf[BUFF_SIZE + 1];
	char			*p_n;
	char			*tmp;
	int				rd;

	p_n = NULL;
	rd = 1;
	*line = checkhist(&p_n, hist);
	while (p_n == 0 && ((rd = read(fd, buf, BUFF_SIZE)) != 0))
	{
		buf[rd] = '\0';
		if ((p_n = ft_strchr(buf, '\n')) != NULL)
		{
			ft_strcpy(hist, ++p_n);
			ft_strclr(--p_n);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(tmp, buf)) || rd < 0)
			return (-1);
		ft_strdel(&tmp);
	}
	return ((ft_strlen(*line) || ft_strlen(hist) || rd) ? 1 : 0);
}

int			get_next_line(const int fd, char **line)
{
	static t_tail	*tail;
	t_tail			*tmp;
	int				ret;

	if (fd < 0 || line == 0)
		return (-1);
	if (!tail)
		tail = newtail(fd);
	tmp = tail;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = newtail(fd);
		tmp = tmp->next;
	}
	ret = get_line(fd, line, tmp->hist);
	return (ret);
}
