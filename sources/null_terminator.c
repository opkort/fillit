/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null_terminator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihilmar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:22:59 by ihilmar           #+#    #+#             */
/*   Updated: 2020/02/20 21:23:01 by ihilmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		null_terminate_row_storage(t_matrix **row_storage)
{
	t_matrix	*pre_last_row;
	t_matrix	*last_row;

	if ((*row_storage)->down == 0)
	{
		(*row_storage) = 0;
		return ;
	}
	pre_last_row = *row_storage;
	last_row = *row_storage;
	while (last_row->down != 0)
		last_row = last_row->down;
	while (pre_last_row->down != last_row)
		pre_last_row = pre_last_row->down;
	while (pre_last_row != 0)
	{
		pre_last_row->down = 0;
		pre_last_row = pre_last_row->right;
	}
}

void		null_terminate_solution(t_matrix **solution, t_matrix *rowlast)
{
	t_matrix	*tmp;

	tmp = *solution;
	if ((*solution)->down == 0)
	{
		*solution = 0;
		return ;
	}
	while (tmp->down != rowlast)
		tmp = tmp->down;
	while (tmp != 0)
	{
		tmp->down = 0;
		tmp = tmp->right;
	}
}

void		null_terminate_col_storage(t_matrix **col_storage)
{
	t_matrix	*pre_last_col;
	t_matrix	*last_col;

	if ((*col_storage)->right == 0)
	{
		(*col_storage) = 0;
		return ;
	}
	pre_last_col = *col_storage;
	last_col = *col_storage;
	while (last_col->right != 0)
		last_col = last_col->right;
	while (pre_last_col->right != last_col)
		pre_last_col = pre_last_col->right;
	while (pre_last_col != 0)
	{
		pre_last_col->right = 0
		;
		pre_last_col = pre_last_col->down;
	}
}
