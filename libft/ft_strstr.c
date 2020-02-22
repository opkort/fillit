/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 21:36:43 by pgenesis          #+#    #+#             */
/*   Updated: 2019/09/22 22:06:52 by pgenesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *h, const char *n)
{
	int i;
	int j;

	if (*n == '\0')
		return ((char *)h);
	i = 0;
	while (h[i])
	{
		j = 0;
		while (n[j] == h[i + j])
		{
			if (n[j + 1] == '\0')
				return ((char *)h + i);
			j++;
		}
		i++;
	}
	return (0);
}
