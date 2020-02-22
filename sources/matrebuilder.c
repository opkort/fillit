/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrebuilder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihilmar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:08:05 by ihilmar           #+#    #+#             */
/*   Updated: 2020/02/20 21:08:08 by ihilmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		rebuild_matrix(t_matrix **storage, t_matrix **solution,
							t_matrix **matrix)
{
	int			tetro_id;
	t_matrix	*tmp;

	storage[0] = 0;
	storage[1] = 0;
	tmp = storage[2];
	tetro_id = tmp->tetro_id;
	row_to_solution(solution, tmp);
	matrix_delete_row(matrix, &tmp);
	tmp = *matrix;
	while (tmp != 0 && (*matrix != 0))
	{
		if (tmp->tetro_id == tetro_id)
		{
			row_to_storage(&storage[0], tmp);
			matrix_delete_row(matrix, &tmp);
		}
		else
			tmp = tmp->down;
	}
	if (*matrix != 0)
		remove_rows(matrix, &storage[0], *solution);
	if (*matrix != 0)
		remove_cols(matrix, &storage[1], *solution);
}

int			check_empty_cols(t_matrix *matrix)
{
	t_matrix	*col;
	t_matrix	*row;
	int			empty_cols;
	int			flag;

	if (matrix == 0)
		return (0);
	col = matrix;
	flag = 0;
	empty_cols = 0;
	while (col != 0)
	{
		flag = 0;
		row = col;
		while (row != 0)
		{
			if (row->is_filled == 1)
				flag++;
			row = row->down;
		}
		if (flag == 0)
			empty_cols++;
		col = col->right;
	}
	return (empty_cols);
}

int			decision_condition(t_matrix *solution, int tetros_area)
{
	int			tetros_nb;
	int			i;

	i = 0;
	tetros_nb = tetros_area / 4;
	while (solution != 0)
	{
		i++;
		solution = solution->down;
	}
	if (tetros_nb == i)
		return (0);
	else
		return (-1);
}

int			check_cols(t_matrix *matrix, t_matrix *solution,
						int size, int tetros_area)
{
	int			empty_cols;
	int			squarea;

	squarea = size * size;
	if (decision_condition(solution, tetros_area) == 0)
		return (0);
	if (matrix == 0)
		return (1);
	empty_cols = check_empty_cols(matrix);
	if (empty_cols > squarea - tetros_area)
		return (1);
	return (2);
}

t_matrix	*find_row(t_matrix *matrix, t_matrix *rts)
{
	t_matrix	*col;
	t_matrix	*row;

	col = matrix;
	row = matrix;
	while (row != 0)
	{
		col = row;
		while (col != 0)
		{
			if (col == rts)
				return (row);
			col = col->right;
		}
		row = row->down;
	}
	return (0);
}
