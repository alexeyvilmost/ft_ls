/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 00:11:05 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/26 02:25:12 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_dot - return index of dot in double nline, or 0 if there's no dot
*/

size_t	ft_dot(const char *str)
{
	int	i;

	i = ft_strfchr(str, '.');
	if (i == -1)
		return (0);
	return (i);
}

/*
** ft_adot - count symbols after dot in double nline, or 0 if there no dot
*/

size_t	ft_adot(const char *str)
{
	if (!ft_dot(str))
		return (0);
	return (ft_strlen(str) - ft_dot(str) - 1);
}

/*
** ft_longcmp - behaviour is similar to strcmp, but compare nlines
** instead of string
*/

int		ft_longcmp(t_cchar n1, t_cchar n2)
{
	const size_t	dot1 = ft_dot(n1);
	const size_t	dot2 = ft_dot(n2);
	size_t			len1;
	size_t			len2;

	len1 = (dot1) ? dot1 : ft_strlen(n1);
	len2 = (dot2) ? dot2 : ft_strlen(n2);
	if (len1 == len2)
		return (ft_strcmp(n1, n2));
	return (len1 > len2 ? 1 : -1);
}

/*
** ft_put_dot - put '.' in string and free it if needed
*/

char	*ft_put_dot(char *str, size_t where, _Bool to_free)
{
	char			*ret;
	char			*buff;
	const size_t	len = ft_strlen(str);
	size_t			a;

	buff = (len > where) ? ft_strdup(str) :
			ft_strjoinfree(ft_get(where - len, '0'), str, -1, 1);
	a = ft_abs(len - where);
	ret = ft_strjoinfree(ft_strsub(buff, 0, a),
			ft_strjoinfree(".",
			ft_strsub(buff, a, len - a), -1, 3), -1, 2);
	free(buff);
	if (to_free)
		free(str);
	return (ret);
}
