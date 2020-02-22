/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rows_remover.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihilmar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:11:49 by ihilmar           #+#    #+#             */
/*   Updated: 2020/02/20 21:11:51 by ihilmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		remove_rows(t_matrix **matrix, t_matrix **row_storage,
						t_matrix *solution)
{
	t_matrix	*mat;
	t_matrix	*col;

	mat = *matrix;
	while (solution->down != 0)
		solution = solution->down;
	while (solution != 0)
	{
		if (solution->is_filled == 1)
		{
			col = mat;
			while (col != 0)
			{
				if (col->is_filled == 1)
					rem_rows_helper(&col, &mat, matrix, row_storage);
				else
					col = col->down;
			}
		}
		if (mat == 0)
			return ;
		mat = mat->right;
		solution = solution->right;
	}
}

void		rem_rows_helper(t_matrix **col, t_matrix **mat,
							t_matrix **matrix, t_matrix **row_storage)
{
	t_matrix	*tmp;

	tmp = *col;
	*col = (*col)->down;
	if (tmp == *mat)
		*mat = (*mat)->down;
	tmp = find_row(*matrix, tmp);
	row_to_storage(row_storage, tmp);
	matrix_delete_row(matrix, &tmp);
}

void		row_to_storage(t_matrix **row_storage, t_matrix *row)
{
	t_matrix	*tmp;

	tmp = *row_storage;
	if (*row_storage == 0)
	{
		*row_storage = row;
		while (row != 0)
		{
			row->pos_in_matrix = row->down;
			row = row->right;
		}
		return ;
	}
	while (tmp->down != 0)
		tmp = tmp->down;
	while (tmp != 0)
	{
		tmp->down = row;
		row->pos_in_matrix = row->down;
		row = row->right;
		tmp = tmp->right;
	}
}

void		row_to_solution(t_matrix **solution, t_matrix *row)
{
	t_matrix	*tmp;

	tmp = *solution;
	if (*solution == 0)
	{
		*solution = row;
		while (row != 0)
		{
			row->pos_in_matrix = row->down;
			row = row->right;
		}
		return ;
	}
	while (tmp->down != 0)
		tmp = tmp->down;
	while (row != 0)
	{
		tmp->down = row;
		row->pos_in_matrix = row->down;
		row = row->right;
		tmp = tmp->right;
	}
}
