/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:27:48 by pgenesis          #+#    #+#             */
/*   Updated: 2019/09/23 23:55:17 by pgenesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		str[i] = (*f)(s[i]);
		i--;
	}
	return (str);
}
