/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:53:57 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/26 02:25:12 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int to_find, size_t size)
{
	size_t			i;
	unsigned char	*buff;

	i = 0;
	buff = (unsigned char *)arr;
	while (i < size && *buff++ != (unsigned char)to_find)
		i++;
	if (i != size)
		return ((void *)--buff);
	return (NULL);
}
