/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:10:38 by pgenesis          #+#    #+#             */
/*   Updated: 2020/02/20 19:10:41 by pgenesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetro		*new_tetro(t_tetro *ptr)
{
	t_tetro	*tmp;

	tmp = ptr;
	if (!(tmp->next = (t_tetro *)malloc(sizeof(t_tetro))))
		return (0);
	ptr = tmp->next;
	ptr->next = 0;
	return (ptr);
}

void		free_struct(t_matrix *matrix)
{
	t_matrix	*tmp1;
	t_matrix	*tmp2;
	t_matrix	*tmp3;

	if (matrix == 0)
		return ;
	tmp1 = matrix;
	tmp2 = matrix;
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
}

void		free_tetro(t_tetro *tetros)
{
	t_tetro	*tmp1;
	t_tetro	*tmp2;

	tmp1 = tetros->next;
	tmp2 = tetros->next;
	while (tmp1 != 0)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
		free(tmp2);
	}
}

void		del_last_tetros(t_tetro *tetros)
{
	t_tetro	*tmp;

	tmp = tetros;
	while (tetros->next != 0)
		tetros = tetros->next;
	while (tmp->next != tetros)
		tmp = tmp->next;
	tmp->next = 0;
	free(tetros);
}

void		fillit(char *name)
{
	int				fd;
	t_tetro			tetros;
	t_matrix		*solution;
	t_matrix		*matrix;

	solution = 0;
	matrix = 0;
	fd = open(name, O_RDONLY);
	if (valid(fd, &tetros) == -1 || (fd == -1))
	{
		write(1, "error\n", 6);
		return ;
	}
	del_last_tetros(&tetros);
	builder(&tetros, &solution, &matrix);
	free_tetro(&tetros);
	free_struct(solution);
	free_struct(matrix);
	close(fd);
}
