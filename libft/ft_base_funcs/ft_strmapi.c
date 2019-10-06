/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 00:04:48 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/26 02:25:12 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
	{
		newstr[i] = f(i, *buffstr++);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
