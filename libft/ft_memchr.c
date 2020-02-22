/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 21:27:00 by pgenesis          #+#    #+#             */
/*   Updated: 2019/09/23 23:20:14 by pgenesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	size_t			i;
	unsigned char	*arrc;

	arrc = (unsigned char *)arr;
	i = 0;
	while (i < n)
	{
		if (arrc[i] == (unsigned char)c)
			return (&arrc[i]);
		i++;
	}
	return (NULL);
}
