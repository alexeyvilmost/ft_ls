/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_div.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 02:55:52 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/26 02:25:12 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*div_ender(char *num[10], t_llong s, char *div, short accur)
{
	char	*ret;
	char	*temp;
	t_llong	j;
	size_t	i;

	i = 0;
	ret = ft_strnew(ft_strlen(div) + accur + 1);
	while (--s >= 0)
	{
		j = 10;
		temp = ft_nline(s + 1, num[--j], 0);
		while (ft_longcmp(div, temp) < 0 && j > 0)
		{
			free(temp);
			temp = ft_nline(s + 1, num[--j], 0);
		}
		(j > 0) ? div = ft_long(div, temp, '-', 1) : 0;
		free(temp);
		ret[i++] = j + '0';
	}
	free(div);
	return (ret);
}

/*
** l_base_div - divide one nline to the other by column division algo
*/

static char	*l_base_div(char *divider, char *dividend, short accur)
{
	char	*ret;
	char	*num[10];
	char	*temp;
	t_llong	s;

	s = 1;
	num[1] = ft_strdup(dividend);
	while (++s < 10)
		num[s] = ft_long(dividend, num[s - 1], '+', 0);
	s = accur;
	temp = ft_nline(++s, dividend, 0);
	while (ft_longcmp(divider, temp) > 0)
	{
		free(temp);
		temp = ft_nline(++s, dividend, 0);
	}
	free(temp);
	ret = div_ender(num, s, divider, accur);
	s = 0;
	while (++s < 10)
		free(num[s]);
	return (ret);
}

/*
** ft_long_div - prepare nline before division
*/

char		*ft_long_div(char *first, char *second, short accur)
{
	char	*fst;

	fst = (accur) ? ft_nline(accur + 1, first, 0) : ft_strdup(first);
	if (ft_strequ(first, "0") || ft_strequ(second, "0"))
		return (ft_nline(-accur, "0", 0));
	if (!ft_dot(first) && !ft_dot(second))
	{
		if (!accur)
			return (l_base_div(fst, second, accur));
		else
			return (ft_put_dot(l_base_div(fst, second, accur), accur, 1));
	}
	return (ft_strdup(first));
}
