/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 21:26:34 by pgenesis          #+#    #+#             */
/*   Updated: 2019/09/23 23:19:11 by pgenesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*area;
	size_t	i;

	if (!(area = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		area[i] = 0;
		i++;
	}
	return (area);
}
