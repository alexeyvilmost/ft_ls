/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:57:14 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/26 02:25:12 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*newstr;
	char	*buffstr;
	size_t	i;

	i = 0;
	buffstr = (char *)s;
	if (!s || !f ||
			!(newstr = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (*buffstr)
		newstr[i++] = f(*buffstr++);
	newstr[i] = '\0';
	return (newstr);
}
