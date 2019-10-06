/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 11:16:24 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/26 02:25:12 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_get - return NULL-terminated string with number of symbols
*/

char	*ft_get(int amount, int symbol)
{
	char	*nulles;
	char	*ret;

	if (amount < 0)
		return (ft_strnew(1));
	nulles = ft_memsetloc(amount + 1, symbol);
	ret = ft_strsub(nulles, 0, amount);
	free(nulles);
	return (ret);
}
