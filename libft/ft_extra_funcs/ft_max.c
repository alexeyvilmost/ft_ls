/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 09:58:56 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/26 02:25:12 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_max - return maximum of two input values
** ft_min - return minimum of two input values
*/

t_llong		ft_max(t_llong first_num, t_llong second_num)
{
	return (first_num >= second_num ? first_num : second_num);
}

t_llong		ft_min(t_llong first_num, t_llong second_num)
{
	return (first_num <= second_num ? first_num : second_num);
}
