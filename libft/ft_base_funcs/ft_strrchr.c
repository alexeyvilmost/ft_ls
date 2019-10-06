/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:25:57 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/26 02:25:12 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int to_find)
{
	size_t	size;

	if (!(size = ft_strlen(str) + 1) && (char)to_find != '\0')
		return (NULL);
	while (--size > 0)
		if (str[size] == (char)to_find)
			return ((char *)&str[size]);
	if (str[0] == (char)to_find)
		return ((char *)&str[0]);
	return (NULL);
}
