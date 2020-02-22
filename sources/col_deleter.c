/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_deleter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihilmar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:16:11 by ihilmar           #+#    #+#             */
/*   Updated: 2020/02/20 21:16:12 by ihilmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		del_first_col(t_matrix **matrix, t_matrix *col)
{
	t_matrix	*tmp;

	tmp = *matrix;
	*matrix = (*matrix)->right;
	while (col != 0)
	{
		col->right = 0;
		col = col->down;
	}
}

void		del_norm_col(t_matrix **matrix, t_matrix *col)
{
	t_matrix	*tmp;

	tmp = *matrix;
	while (tmp->right != col)
		tmp = tmp->right;
	while (tmp != 0)
	{
		tmp->right = col->right;
		col->right = 0;
		col = col->down;
		tmp = tmp->down;
	}
}

void		matrix_delete_col(t_matrix **matrix, t_matrix **ptr)
{
	t_matrix	*tmp;
	t_matrix	*col;

	if (*matrix == 0 || *ptr == 0)
		return ;
	col = *ptr;
	*ptr = (*ptr)->right;
	tmp = *matrix;
	if (col == tmp)
		del_first_col(matrix, col);
	else
		del_norm_col(matrix, col);
}
