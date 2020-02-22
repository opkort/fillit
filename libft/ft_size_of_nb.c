/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_of_nb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 22:59:22 by pgenesis          #+#    #+#             */
/*   Updated: 2019/09/24 23:04:08 by pgenesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size_of_nb(int n)
{
	unsigned int	size;

	size = 0;
	while (n / 10 != 0)
	{
		n /= 10;
		size++;
	}
	return (size + 1);
}
