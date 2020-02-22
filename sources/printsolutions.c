/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printsolutions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihilmar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:25:27 by ihilmar           #+#    #+#             */
/*   Updated: 2020/02/20 21:25:28 by ihilmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		null_init_arr(int size, int arr[][size])
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (j < size)
	{
		while (i < size)
		{
			arr[j][i] = 0;
			i++;
		}
		i = 0;
		j++;
	}
}

void		init_arr(t_matrix *matrix, int size, int arr[][size])
{
	t_matrix	*tmp;

	tmp = matrix;
	while (tmp)
	{
		if (tmp->is_filled)
			arr[tmp->coord[1]][tmp->coord[0]] = tmp->tetro_id;
		if (tmp->right)
			tmp = tmp->right;
		else
		{
			matrix = matrix->down;
			tmp = matrix;
		}
	}
}

void		print_tetro_arr(int size, int arr[][size])
{
	int			i;
	int			j;
	char		c;

	j = 0;
	i = 0;
	while (j < size)
	{
		while (i < size)
		{
			if (!arr[j][i])
				c = 46;
			else
				c = 64 + arr[j][i];
			write(1, &c, 1);
			i++;
		}
		write(1, "\n", 1);
		i = 0;
		j++;
	}
}

void		print_solutions(t_matrix *matrix, int size)
{
	int			arr[size][size];

	null_init_arr(size, arr);
	init_arr(matrix, size, arr);
	print_tetro_arr(size, arr);
}
