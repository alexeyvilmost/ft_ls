/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 20:47:06 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/26 02:25:12 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_pow - raise number to a power, for decimal nums
** ft_pow_dbl - raise number to a power, for power < 0 or double nums
*/

t_llong		ft_pow(t_llong to_raise, short power)
{
	if (power == 0)
		return (1);
	if (power > 0)
		return (to_raise * ft_pow(to_raise, --power));
	else
		return (ft_pow(to_raise, ++power) / to_raise);
}

long double	ft_pow_dbl(long double to_raise, short power)
{
	if (power == 0)
		return (1l);
	else if (power > 0)
		return (to_raise * ft_pow_dbl(to_raise, --power));
	else
		return (ft_pow_dbl(to_raise, ++power) / to_raise);
}
