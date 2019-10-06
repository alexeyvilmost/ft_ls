/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:00:16 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/26 02:25:12 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dsize;

	if (!size)
		return (ft_strlen(dest));
	i = 0;
	j = 0;
	while (dest[i] && i < size)
		i++;
	dsize = i;
	while (src[j] && i < size - 1)
		dest[i++] = src[j++];
	if (dsize < size)
		dest[i] = '\0';
	return (dsize + ft_strlen(src));
}
