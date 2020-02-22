/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newstater.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihilmar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:02:35 by ihilmar           #+#    #+#             */
/*   Updated: 2020/02/20 21:02:36 by ihilmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			new_cell(t_matrix **matrix, int coords[])
{
	t_matrix *tmp;
	t_matrix *run_ptr;

	if (!(tmp = (t_matrix *)malloc(sizeof(t_matrix))))
		return (-1);
	tmp->coord[0] = coords[0];
	tmp->coord[1] = coords[1];
	tmp->is_filled = 0;
	tmp->pos_in_matrix = 0;
	tmp->tetro_id = 0;
	tmp->down = 0;
	tmp->right = 0;
	run_ptr = *matrix;
	if (*matrix)
	{
		while (run_ptr->right)
			run_ptr = run_ptr->right;
		run_ptr->right = tmp;
	}
	else
		*matrix = tmp;
	return (0);
}

void		init_state(t_matrix **matrix, t_tetro *tetros, int tetro_id)
{
	int			cur_pt;
	t_matrix	*tmp;

	tmp = *matrix;
	cur_pt = 0;
	while (tmp)
	{
		tmp->tetro_id = tetro_id;
		if (tetros->points[cur_pt][0] == tmp->coord[0] &&
		tetros->points[cur_pt][1] == tmp->coord[1] && cur_pt < 4)
		{
			tmp->is_filled = 1;
			cur_pt++;
		}
		else
			tmp->is_filled = 0;
		tmp = tmp->right;
	}
}

t_matrix	*create_state(t_tetro *tetros, int size, int tetro_id)
{
	t_matrix	*matrix;
	int			coords[2];

	coords[0] = 0;
	coords[1] = 0;
	matrix = 0;
	while (coords[0] < size && coords[1] < size)
	{
		if (new_cell(&matrix, coords) == -1)
			return (0);
		if (coords[0] == size - 1)
		{
			coords[0] = 0;
			coords[1]++;
		}
		else
			coords[0]++;
	}
	init_state(&matrix, tetros, tetro_id);
	return (matrix);
}

int			is_right_shift(t_tetro *tetros, int size)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (tetros->points[i][0] + 1 < size)
			i++;
		else
			i = 5;
	}
	if (i == 5)
		return (1);
	i = 0;
	while (i < 4)
	{
		tetros->points[i][0]++;
		i++;
	}
	return (0);
}
