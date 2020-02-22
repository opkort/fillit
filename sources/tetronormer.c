/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetronormer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihilmar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:26:55 by ihilmar           #+#    #+#             */
/*   Updated: 2020/02/20 21:26:56 by ihilmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		move_tetro(t_tetro *tmp, int x, int y)
{
	int			i;

	i = 0;
	while (i < 4)
	{
		tmp->points[i][0] -= x;
		tmp->points[i][1] -= y;
		i++;
	}
}

void		norm_tetro(t_tetro *tetros)
{
	int			x;
	int			y;
	t_tetro		*tmp;
	int			i;

	tmp = tetros;
	while (tmp != 0)
	{
		i = 0;
		x = 4;
		y = 4;
		while (i < 4)
		{
			if (tmp->points[i][0] < x)
				x = tmp->points[i][0];
			if (tmp->points[i][1] < y)
				y = tmp->points[i][1];
			i++;
		}
		move_tetro(tmp, x, y);
		tmp = tmp->next;
	}
}

int			check_tetros_types(t_tetro *tetros)
{
	int			i;
	int			min[2];
	int			max[2];

	i = 0;
	min[0] = tetros->points[0][0];
	min[1] = tetros->points[0][1];
	max[0] = tetros->points[0][0];
	max[1] = tetros->points[0][1];
	while (i < 4)
	{
		if (min[0] > tetros->points[i][0])
			min[0] = tetros->points[i][0];
		if (min[1] > tetros->points[i][1])
			min[1] = tetros->points[i][1];
		if (max[0] < tetros->points[i][0])
			max[0] = tetros->points[i][0];
		if (max[1] < tetros->points[i][1])
			max[1] = tetros->points[i][1];
		i++;
	}
	if (max[0] - min[0] >= max[1] - min[1])
		return (max[0] - min[0]);
	return (max[1] - min[1]);
}

int			min_size(int tetros_area, t_tetro *tetros)
{
	int			i;
	int			tetro_len;

	i = 2;
	while (i * i < tetros_area)
		i++;
	if (i < 4)
	{
		while (tetros != 0)
		{
			tetro_len = check_tetros_types(tetros);
			if (tetro_len == 3)
				return (4);
			if (tetro_len == 2 && i == 2)
				i = 3;
			tetros = tetros->next;
		}
	}
	return (i);
}

int			ft_tetros_area(t_tetro *tetros)
{
	t_tetro		*tmp;
	int			i;

	i = 1;
	tmp = tetros;
	while (tmp->next != 0)
	{
		i++;
		tmp = tmp->next;
	}
	return (i * 4);
}
