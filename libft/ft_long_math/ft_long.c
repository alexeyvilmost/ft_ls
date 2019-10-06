/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 14:43:39 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/26 02:25:12 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
** Take two number's string representations and option that can be '+', '-' or
** '/' and return string-result of action, with free one of strings in the end
*/

char	*ft_long(char *first_num, char *second_num, char option, short to_free)
{
	t_llong	i;
	char	*ret;
	char	*result;

	if (option == '+')
		ret = ft_long_sum(first_num, second_num);
	else if (option == '-')
		ret = ft_long_diff(first_num, second_num);
	else if (option == '/')
		ret = ft_long_div(first_num, second_num,
				to_free < 0 ? ft_abs(to_free) : 0);
	else
		ret = ft_long_mult(first_num, second_num);
	i = 0;
	while (ret[i] == '0')
		i++;
	result = ret[i] ? ft_strsub(ret, i, ft_strlen(ret) - i) : ft_strdup("0");
	free(ret);
	if (result[0] == '.')
		result = ft_strjoinfree("0", result, -1, 3);
	if (to_free > 1 || option == '/')
		free(second_num);
	if ((to_free > 0 && to_free < 3) || option == '/')
		free(first_num);
	return (result);
}
