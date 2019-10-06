/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_mult.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 20:25:15 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/26 02:25:12 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_long_mult(char *fst, char *snd)
{
	char	*ret;
	char	*num[9];
	short	i;
	t_llong	j;

	i = 0;
	j = ft_strlen(snd);
	num[0] = ft_strdup(fst);
	while (++i < 9)
		num[i] = ft_long(fst, num[i - 1], '+', 0);
	i = 1;
	ret = (snd[--j] - 49 >= 0) ? ft_strdup(num[snd[j] - 49]) : ft_strdup("0");
	while (--j > -1)
		if (++i && snd[j] - 49 >= 0)
			ret = ft_long(ret, ft_nline(i, num[snd[j] - 49], 0), '+', 2);
	j = -1;
	while (++j < 9)
		free(num[j]);
	return (ret);
}
