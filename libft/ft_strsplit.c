/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:37:25 by pgenesis          #+#    #+#             */
/*   Updated: 2019/09/24 23:13:30 by pgenesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(const char *s, char c)
{
	int		wc;
	int		sc;
	int		i;
	int		j;
	char	**fresh;

	if (!s)
		return (0);
	i = 0;
	wc = count_words(s, c);
	if (!(fresh = (char **)malloc(sizeof(char *) * (wc + 1))))
		return (NULL);
	fresh[wc] = NULL;
	while (i < wc)
	{
		j = 0;
		while (*s == c)
			s++;
		sc = count_symbols(s, c);
		if (!(fresh[i] = (char *)malloc(sizeof(char) * sc + 1)))
			return ((char **)ft_free_array(&fresh, i));
		get_word(&s, sc, &i, &fresh);
		fresh[i++][sc] = '\0';
	}
	return (fresh);
}
