/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row_deleter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihilmar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:15:05 by ihilmar           #+#    #+#             */
/*   Updated: 2020/02/20 21:15:08 by ihilmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		matrix_delete_row(t_matrix **matrix, t_matrix **ptr)
{
	t_matrix	*tmp;
	t_matrix	*row;

	if (*matrix == 0 || *ptr == 0)
		return ;
	row = *ptr;
	*ptr = (*ptr)->down;
	tmp = *matrix;
	if (row == tmp)
		del_first_row(matrix, row);
	else
		del_normal_row(matrix, row);
}

void		del_normal_row(t_matrix **matrix, t_matrix *row)
{
	t_matrix	*tmp;

	tmp = *matrix;
	while (tmp->down != row)
		tmp = tmp->down;
	while (tmp != 0)
	{
		tmp->down = row->down;
		row->down = 0;
		tmp = tmp->right;
		row = row->right;
	}
}

void		del_first_row(t_matrix **matrix, t_matrix *row)
{
	t_matrix	*tmp;

	tmp = *matrix;
	*matrix = (*matrix)->down;
	while (row != 0)
	{
		row->down = 0;
		row = row->right;
	}
}
