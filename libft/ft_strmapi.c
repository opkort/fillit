/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:58:14 by pgenesis          #+#    #+#             */
/*   Updated: 2019/09/23 23:54:38 by pgenesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	if (!s || !f)
		return (0);
	i = ft_strlen(s);
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (0);
	str[i--] = '\0';
	while (i >= 0)
	{
		str[i] = (*f)(i, s[i]);
		i--;
	}
	return (str);
}
