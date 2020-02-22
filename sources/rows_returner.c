/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rows_returner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihilmar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:21:31 by ihilmar           #+#    #+#             */
/*   Updated: 2020/02/20 21:21:33 by ihilmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		return_first_row(t_matrix **matrix, t_matrix *row)
{
	t_matrix	*mat;

	mat = *matrix;
	*matrix = row;
	while (row != 0)
	{
		row->down = mat;
		row->pos_in_matrix = 0;
		row = row->right;
		mat = mat->right;
	}
}

void		return_norm_row(t_matrix **matrix, t_matrix *row)
{
	t_matrix	*mat;

	mat = *matrix;
	while (mat->down != row->pos_in_matrix)
		mat = mat->down;
	while (mat != 0)
	{
		mat->down = row;
		row->down = row->pos_in_matrix;
		row->pos_in_matrix = 0;
		mat = mat->right;
		row = row->right;
	}
}

void		return_row(t_matrix **matrix, t_matrix **row_storage)
{
	t_matrix	*row;

	if (*row_storage == 0)
		return ;
	row = *row_storage;
	while (row->down != 0)
		row = row->down;
	null_terminate_row_storage(row_storage);
	if (*matrix == 0)
	{
		*matrix = row;
		while (row != 0)
		{
			row->pos_in_matrix = 0;
			row = row->right;
		}
		return ;
	}
	if (row->pos_in_matrix == *matrix)
	{
		return_first_row(matrix, row);
		return ;
	}
	return_norm_row(matrix, row);
}

void		from_solution_to_beginning(t_matrix **matrix, t_matrix **solution)
{
	t_matrix	*sol;
	t_matrix	*mat;

	sol = *solution;
	mat = *matrix;
	while (sol->down != 0)
		sol = sol->down;
	*matrix = sol;
	null_terminate_solution(solution, sol);
	while (sol != 0)
	{
		sol->down = mat;
		sol = sol->right;
		mat = mat->right;
	}
}

void		return_row_from_solution(t_matrix **matrix, t_matrix **solution)
{
	t_matrix	*sol;
	t_matrix	*mat;

	sol = *solution;
	mat = *matrix;
	while (sol->down != 0)
		sol = sol->down;
	if (sol->pos_in_matrix == *matrix)
	{
		from_solution_to_beginning(matrix, solution);
		return ;
	}
	null_terminate_solution(solution, sol);
	while (mat->down != sol->pos_in_matrix)
		mat = mat->down;
	while (mat != 0)
	{
		mat->down = sol;
		sol->down = sol->pos_in_matrix;
		sol = sol->right;
		mat = mat->right;
	}
}
