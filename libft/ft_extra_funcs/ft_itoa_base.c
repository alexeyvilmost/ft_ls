/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 18:43:10 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/26 02:25:12 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_itoa_base - converts integer to its strings representation
** functions works similar to ft_ft_itoa, except for 2 additional fields:
** base - contains numeric system base
** letter - contains char, which case will be used for over 10-base systems
*/

static char	overbase(t_ushort n, char letter)
{
	if (n < 10)
		return (n + '0');
	else
		return (ft_isupper(letter) ? n + 55 : n + 87);
}

char		*ft_itoa_base(t_ullong num, t_ushort base, char letter)
{
	size_t		i;
	t_ullong	mult;
	char		*ret;

	i = 0;
	if (!base)
		base = 10;
	ret = ft_strnew(ft_nsize_base(num, base));
	if (!num)
	{
		ret[0] = '0';
		return (ret);
	}
	mult = ft_nmult_base(num, base);
	while (mult)
	{
		ret[i++] = overbase(num / mult, letter);
		num -= (num / mult) * mult;
		mult /= base;
	}
	ret[i] = '\0';
	return (ret);
}
