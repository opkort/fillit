/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:08:47 by pgenesis          #+#    #+#             */
/*   Updated: 2020/02/20 19:08:50 by pgenesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_putstr("usage: this program must take only one parameter");
		return (0);
	}
	fillit(argv[1]);
	return (0);
}
