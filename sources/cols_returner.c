/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cols_returner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihilmar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:19:48 by ihilmar           #+#    #+#             */
/*   Updated: 2020/02/20 21:19:50 by ihilmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		return_first_col(t_matrix **matrix, t_matrix *col)
{
	t_matrix	*mat;

	mat = *matrix;
	*matrix = col;
	while (col != 0)
	{
		col->right = mat;
		col->pos_in_matrix = 0;
		col = col->down;
		mat = mat->down;
	}
}

void		return_norm_col(t_matrix **matrix, t_matrix *col)
{
	t_matrix	*mat;

	mat = *matrix;
	while (mat->right != col->pos_in_matrix)
		mat = mat->right;
	while (mat != 0)
	{
		mat->right = col;
		col->right = col->pos_in_matrix;
		col->pos_in_matrix = 0;
		mat = mat->down;
		col = col->down;
	}
}

void		return_col(t_matrix **matrix, t_matrix **col_storage)
{
	t_matrix	*col;

	if (*col_storage == 0)
		return ;
	col = *col_storage;
	while (col->right != 0)
		col = col->right;
	null_terminate_col_storage(col_storage);
	if (*matrix == 0)
	{
		*matrix = col;
		while (col != 0)
		{
			col->pos_in_matrix = 0;
			col = col->down;
		}
		return ;
	}
	if (col->pos_in_matrix == *matrix)
	{
		return_first_col(matrix, col);
		return ;
	}
	return_norm_col(matrix, col);
}
