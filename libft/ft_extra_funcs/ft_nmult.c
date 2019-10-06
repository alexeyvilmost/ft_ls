/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:20:26 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/26 02:25:12 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_nmult - return max number divident, which also a power of 10 (345 - 100)
** ft_nmult_base - return max number divident, which also a power of base
*/

t_ullong	ft_nmult_base(t_ullong to_count, short base)
{
	size_t	mult;

	mult = 1;
	while (to_count /= base)
		mult *= base;
	return (mult);
}

t_ullong	ft_nmult(t_ullong to_count)
{
	return (ft_nmult_base(to_count, 10));
}
