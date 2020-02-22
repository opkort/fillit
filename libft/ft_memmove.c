/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 21:51:22 by pgenesis          #+#    #+#             */
/*   Updated: 2019/09/23 23:32:57 by pgenesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*pdest;
	char	*psrc;
	size_t	i;

	psrc = (char *)src;
	pdest = (char *)dest;
	if (psrc < pdest)
	{
		i = 1;
		while (i <= n)
		{
			pdest[n - i] = psrc[n - i];
			i++;
		}
	}
	else if (psrc > pdest)
	{
		i = 0;
		while (i < n)
		{
			pdest[i] = psrc[i];
			i++;
		}
	}
	return (dest);
}
