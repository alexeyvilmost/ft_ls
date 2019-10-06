/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strerase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 15:25:14 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/26 02:25:12 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strerase - returns new string without part, starting on (start_pow), with
** (size) length
*/

char	*ft_strerase(const char *to_erase, int start_pos, int size)
{
	char	*new;

	if (!to_erase || start_pos < 0 ||
			size + (size_t)start_pos > ft_strlen(to_erase) ||
			!(new = ft_strnew(ft_strlen(to_erase) - size)))
		return (FALSE);
	if (!size)
		return (new = ft_strcpy(new, to_erase));
	if (start_pos)
		new = ft_strncpy(new, to_erase, start_pos);
	while (to_erase[start_pos + size])
	{
		new[start_pos] = to_erase[start_pos + size];
		start_pos++;
	}
	return (new);
}
