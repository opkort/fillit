/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 21:13:05 by pgenesis          #+#    #+#             */
/*   Updated: 2019/09/24 21:15:52 by pgenesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_dup(void const *content, size_t content_size)
{
	unsigned char	*s1;
	unsigned char	*s2;
	void			*new;

	if (!(new = ft_memalloc(content_size)))
		return (NULL);
	s1 = (unsigned char*)content;
	s2 = (unsigned char*)new;
	while (*s1)
		*(s2++) = *(s1++);
	return (new);
}
