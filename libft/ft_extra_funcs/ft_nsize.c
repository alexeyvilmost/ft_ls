/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nsize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 17:48:33 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/26 02:25:12 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_nsize - count digits in number
** ft_nsize_base - count digits in number, according on base
*/

short	ft_nsize_base(t_ullong n, short base)
{
	short i;

	i = 1;
	while (n /= base)
		i++;
	return (i);
}

short	ft_nsize(t_ullong n)
{
	return (ft_nsize_base(n, 10));
}
