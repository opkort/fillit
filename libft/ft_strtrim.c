/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:31:51 by pgenesis          #+#    #+#             */
/*   Updated: 2019/09/24 23:24:40 by pgenesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		cspstart(char const *s)
{
	unsigned int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	return (i);
}

static int		cspend(char const *s, int len)
{
	unsigned int i;

	i = len - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	return (len - i - 1);
}

static char		*ifcseqlen(char **str)
{
	if (!(*str = (char *)malloc(sizeof(char))))
		return (0);
	*str[0] = '\0';
	return (*str);
}

char			*ft_strtrim(char const *s)
{
	char			*str;
	unsigned int	i;
	unsigned int	len;
	unsigned int	cs;
	unsigned int	ce;

	if (!s)
		return (0);
	if (!*s)
		return (ft_strnew(0));
	len = ft_strlen(s);
	cs = cspstart(s);
	if (cs == len)
		return (ifcseqlen(&str));
	ce = cspend(s, len);
	if (!(str = (char *)malloc(sizeof(char) * (len - cs - ce + 1))))
		return (0);
	str[len - cs - ce] = '\0';
	i = 0;
	while (cs + i < len - ce)
	{
		str[i] = s[cs + i];
		i++;
	}
	return (str);
}
