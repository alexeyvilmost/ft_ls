/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 15:07:04 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/26 02:25:12 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	spl_word_c(char const *s1, char c)
{
	int i;
	int words;

	if (!s1)
		return (FALSE);
	i = -1;
	words = 0;
	while (s1[++i])
	{
		if (s1[i] != c && s1[i + 1] == c)
			words++;
	}
	if (i > 0 && s1[i - 1] && s1[i - 1] != c)
		words++;
	return (words);
}

static char	*spl_put_word(const char *s1, char c, int *i)
{
	int		j;
	char	*new;
	char	*buff;

	new = ft_strnew(ft_strlen(s1));
	j = *i;
	while (s1[*i] && s1[*i] != c)
		(*i)++;
	buff = ft_strdup(ft_strncpy(new, &s1[j], *i - j));
	free(new);
	return (buff);
}

char		**ft_strsplit(char const *s1, char c)
{
	char	**ret;
	int		i;
	int		j;
	int		words;

	words = spl_word_c(s1, c);
	if (!s1 || !(ret = ft_memalloc((sizeof(char *) * words) + 1)))
		return (FALSE);
	i = 0;
	j = 0;
	while (words--)
	{
		while (s1[i] && s1[i] == c)
			i++;
		ret[j++] = spl_put_word(s1, c, &i);
	}
	ret[j] = NULL;
	return (ret);
}
