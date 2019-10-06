/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 19:16:09 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/26 02:25:12 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		if (s1[i] == s2[i])
		{
			if (s1[i] && s2[i])
				++i;
			else
			{
				if (!s1[i] && s2[i])
					return (-1);
				else if (!s2[i] && s1[i])
					return (1);
				else
					return (0);
			}
		}
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
