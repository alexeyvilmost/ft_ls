/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_nline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 19:32:22 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/26 02:25:12 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_nline(int pos, char *num, _Bool to_free)
{
	char	*nulles;
	char	*ret;

	nulles = ft_get(ft_abs(pos) - 1, '0');
	if (pos > 0)
	{
		if (nulles[0])
			ret = ft_strjoinfree(num, nulles, -1, 0);
		else
			ret = ft_strdup(num);
	}
	else if (pos < 0)
	{
		if (nulles[0])
			ret = ft_strjoinfree("0.",
					ft_strjoinfree(nulles, num, -1, 0), -1, 3);
		else
			ret = ft_strjoinfree("0.", num, -1, 0);
	}
	else
		ret = ft_strdup(num);
	free(nulles);
	if (to_free)
		free(num);
	return (ret);
}

char	*ft_biline(int power)
{
	char	*ret;
	short	times;

	if (!power)
		return (ft_strdup("1"));
	ret = ft_itoa(ft_pow(2, power % 60));
	times = power / 60;
	while (times--)
		ret = ft_long(ret, "1152921504606846976", '*', 1);
	return (ret);
}
