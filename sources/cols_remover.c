/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cols_remover.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihilmar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:17:08 by ihilmar           #+#    #+#             */
/*   Updated: 2020/02/20 21:17:10 by ihilmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		remove_cols_helper(t_matrix **col_storage, t_matrix **matrix,
								t_matrix **tmp, int *flag)
{
	col_to_storage(col_storage, *tmp);
	matrix_delete_col(matrix, tmp);
	*flag = 1;
}

void		remove_cols(t_matrix **matrix, t_matrix **col_storage,
						t_matrix *solution)
{
	t_matrix	*tmp1;
	int			flag;

	tmp1 = *matrix;
	while (solution->down != 0)
		solution = solution->down;
	while (solution != 0)
	{
		flag = 0;
		if (solution->is_filled == 1)
		{
			while (tmp1 != 0 && flag == 0)
			{
				if ((tmp1->coord[0] == solution->coord[0]) &&
					(tmp1->coord[1] == solution->coord[1]))
					remove_cols_helper(col_storage, matrix, &tmp1, &flag);
				else
					tmp1 = tmp1->right;
			}
		}
		solution = solution->right;
	}
}

void		col_to_storage(t_matrix **col_storage, t_matrix *col)
{
	t_matrix	*tmp;

	tmp = *col_storage;
	if (*col_storage == 0)
	{
		*col_storage = col;
		while (col != 0)
		{
			col->pos_in_matrix = col->right;
			col = col->down;
		}
		return ;
	}
	while (tmp->right != 0)
		tmp = tmp->right;
	while (col != 0)
	{
		tmp->right = col;
		col->pos_in_matrix = col->right;
		col = col->down;
		tmp = tmp->down;
	}
}
