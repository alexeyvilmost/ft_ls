/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memsetloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 01:36:01 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/26 02:25:10 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_memsetloc - malloc (size) of memory and fills it with (val)
*/

void	*ft_memsetloc(size_t size, int val)
{
	void	*ret;

	if (!(ret = malloc(size)))
		return (NULL);
	ft_memset(ret, val, size);
	return (ret);
}
