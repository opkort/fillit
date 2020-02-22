/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 23:11:34 by pgenesis          #+#    #+#             */
/*   Updated: 2019/09/24 23:11:54 by pgenesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	get_word(const char **s, int sc, int *i, char ***fresh)
{
	int	j;

	j = 0;
	while (j < sc)
	{
		(*fresh)[*i][j] = **s;
		(*s)++;
		j++;
	}
}
