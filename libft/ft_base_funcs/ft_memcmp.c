/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:58:18 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/26 02:25:12 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *mem1, const void *mem2, size_t size)
{
	unsigned char	*buff1;
	unsigned char	*buff2;

	buff1 = (unsigned char *)mem1;
	buff2 = (unsigned char *)mem2;
	while (size--)
		if (*buff1++ != *buff2++)
			return ((int)*(--buff1) - (int)*(--buff2));
	return (0);
}
