/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrixfill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:31:20 by pgenesis          #+#    #+#             */
/*   Updated: 2020/02/18 21:25:08 by pgenesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			is_down_shift(t_tetro *tetros, int size)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (tetros->points[i][1] + 1 < size)
			i++;
		else
			i = 5;
	}
	if (i == 5)
		return (1);
	i = 0;
	while (i < 4)
	{
		tetros->points[i][1]++;
		i++;
	}
	return (0);
}

void		join_states(t_matrix **matrix, t_matrix *src)
{
	t_matrix *tmp;

	if ((*matrix) == 0)
	{
		*matrix = src;
		return ;
	}
	tmp = *matrix;
	while (tmp->down)
		tmp = tmp->down;
	while (tmp)
	{
		tmp->down = src;
		tmp = tmp->right;
		src = src->right;
	}
}

t_matrix	*form_states(t_tetro *tetros, int size, int tetro_id)
{
	t_matrix	*matrix[2];
	int			right_shift;

	matrix[0] = create_state(tetros, size, tetro_id);
	right_shift = 0;
	while (1)
	{
		if (is_right_shift(tetros, size) == 0)
		{
			if (!(matrix[1] = create_state(tetros, size, tetro_id)))
				return (0);
			join_states(&matrix[0], matrix[1]);
			right_shift++;
		}
		else if ((is_down_shift(tetros, size) == 0))
		{
			move_tetro(tetros, right_shift, 0);
			right_shift = 0;
			if (!(matrix[1] = create_state(tetros, size, tetro_id)))
				return (0);
			join_states(&matrix[0], matrix[1]);
		}
		else
			return (matrix[0]);
	}
}

int			fill_matrix(t_tetro *tetros, t_matrix **matrix, int size)
{
	t_matrix	*tmp;
	int			tetro_id;
	t_tetro		*tmp_tetro;

	free_struct(*matrix);
	*matrix = 0;
	tmp_tetro = tetros;
	tetro_id = 1;
	while (tmp_tetro)
	{
		if ((tmp = form_states(tmp_tetro, size, tetro_id)) == 0)
		{
			norm_tetro(tetros);
			return (-1);
		}
		join_states(matrix, tmp);
		tmp_tetro = tmp_tetro->next;
		tetro_id++;
	}
	norm_tetro(tetros);
	return (0);
}
