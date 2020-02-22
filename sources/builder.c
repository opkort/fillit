/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihilmar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 19:48:42 by ihilmar           #+#    #+#             */
/*   Updated: 2020/01/31 19:03:26 by ihilmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		restore_matrix(t_matrix **storage, t_matrix **solution,
							t_matrix **matrix)
{
	while (storage[1] != 0)
	{
		if (storage[1]->right == 0)
		{
			return_col(matrix, &storage[1]);
			storage[1] = 0;
		}
		else
			return_col(matrix, &storage[1]);
	}
	while (storage[0] != 0)
	{
		if (storage[0]->down == 0)
		{
			return_row(matrix, &storage[0]);
			storage[0] = 0;
		}
		else
			return_row(matrix, &storage[0]);
	}
	return_row_from_solution(matrix, solution);
}

void		free_storage(t_matrix **storage)
{
	t_matrix	*tmp1;
	t_matrix	*tmp2;
	t_matrix	*tmp3;
	int			i;

	i = 0;
	while (i < 2)
	{
		tmp1 = storage[i];
		tmp2 = storage[i];
		while (tmp1 != 0)
		{
			tmp2 = tmp1;
			tmp1 = tmp1->right;
			while (tmp2 != 0)
			{
				tmp3 = tmp2;
				tmp2 = tmp2->down;
				free(tmp3);
			}
		}
		i++;
	}
}

int			algorithm_x(t_matrix **matrix, t_matrix **solution,
						int size, int tetros_area)
{
	t_matrix	*storage[3];
	int			ret[2];

	if ((ret[0] = check_cols(*matrix, *solution, size, tetros_area)) == 1
							|| ret[0] == 0)
		return (ret[0]);
	storage[2] = *matrix;
	while (storage[2] != 0)
	{
		rebuild_matrix(storage, solution, matrix);
		ret[1] = algorithm_x(matrix, solution, size, tetros_area);
		if (ret[1] == 0)
		{
			free_storage(storage);
			return (0);
		}
		else if (ret[1] == 1)
			restore_matrix(storage, solution, matrix);
		storage[2] = storage[2]->down;
	}
	return (1);
}

int			builder(t_tetro *tetros, t_matrix **solution, t_matrix **matrix)
{
	int			check_solution;
	int			size;
	int			x_ret;
	int			tetros_area;

	norm_tetro(tetros);
	*solution = 0;
	tetros_area = ft_tetros_area(tetros);
	size = min_size(tetros_area, tetros);
	check_solution = -1;
	while (check_solution == -1)
	{
		if (fill_matrix(tetros, matrix, size) == -1)
			return (-1);
		if ((x_ret = algorithm_x(matrix, solution, size, tetros_area)) == 1)
			size++;
		else if (x_ret == 0)
			check_solution = 1;
	}
	print_solutions(*solution, size);
	return (0);
}
