/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:55:09 by pgenesis          #+#    #+#             */
/*   Updated: 2020/02/20 18:55:11 by pgenesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_write(char *line, t_tetro *tetros, int pt_nb, int line_nb)
{
	int	i;

	i = 0;
	while (line[i] != 0)
	{
		if (line[i] == '.')
			i++;
		else if (line[i] == '#')
		{
			if (pt_nb == 4)
				return (-1);
			tetros->points[pt_nb][0] = i;
			tetros->points[pt_nb][1] = line_nb;
			pt_nb++;
			i++;
		}
		else
			return (-1);
	}
	if (i != 4)
		return (-1);
	return (pt_nb);
}

int		check_neigh(int i, t_tetro tetro)
{
	int tmp[2];
	int	flag;
	int	k;

	k = 0;
	flag = 0;
	while (k < 4)
	{
		tmp[1] = tetro.points[i][1];
		tmp[0] = tetro.points[i][0] + 1;
		if (tmp[0] == tetro.points[k][0] && tmp[1] == tetro.points[k][1])
			flag++;
		tmp[0] = tetro.points[i][0] - 1;
		if (tmp[0] == tetro.points[k][0] && tmp[1] == tetro.points[k][1])
			flag++;
		tmp[0] = tetro.points[i][0];
		tmp[1] = tetro.points[i][1] + 1;
		if (tmp[0] == tetro.points[k][0] && tmp[1] == tetro.points[k][1])
			flag++;
		tmp[1] = tetro.points[i][1] - 1;
		if (tmp[0] == tetro.points[k][0] && tmp[1] == tetro.points[k][1])
			flag++;
		k++;
	}
	return (flag);
}

int		check_conditions(t_tetro tetro)
{
	int		i;
	int		condition;
	int		flag;

	i = 0;
	condition = 1;
	while (i < 4)
	{
		flag = check_neigh(i, tetro);
		if (flag > 1)
		{
			condition = 0;
			i++;
		}
		else if (flag == 1)
			i++;
		else if (flag == 0)
			return (-1);
	}
	if (condition == 1)
		return (-1);
	return (0);
}

int		read_tetro(int fd, t_tetro *ptr)
{
	char	*line;
	int		j;
	int		gnl_ret;
	int		pt_nb;

	j = 0;
	pt_nb = 0;
	while (j < 4 && (((gnl_ret = get_next_line(fd, &line)) != -1)))
	{
		if ((gnl_ret == 0 && (j != 3)) ||
		((pt_nb = count_write(line, ptr, pt_nb, j)) == -1))
		{
			free(line);
			return (-1);
		}
		j++;
	}
	if (check_conditions(*ptr) == -1)
	{
		free(line);
		return (-1);
	}
	free(line);
	return (0);
}

int		valid(int fd, t_tetro *tetros)
{
	int		i;
	char	*line;
	t_tetro	*ptr;

	i = 1;
	ptr = tetros;
	if (read_tetro(fd, ptr) == -1)
		return (-1);
	if (!(ptr = new_tetro(ptr)))
		return (-1);
	while (get_next_line(fd, &line) == 1 && *line == 0)
	{
		if (i > 25)
			return (-1);
		if (read_tetro(fd, ptr) == -1)
			return (-1);
		if (!(ptr = new_tetro(ptr)))
			return (-1);
		i++;
	}
	if (*line)
		return (-1);
	else
		return (0);
}
