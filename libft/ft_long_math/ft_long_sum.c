/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_sum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 00:36:56 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/26 02:25:12 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** l_base_sum - add one nline to other with column addition algo
*/

static char	*l_base_sum(char *main, char *add, t_llong i, t_llong j)
{
	short	rest;
	char	*ret;

	rest = 0;
	if (ft_strlen(add) > ft_strlen(main))
		return (l_base_sum(add, main, j, i));
	ret = ft_strdup(main);
	while (i >= 0 && j >= 0)
	{
		if (main[i] == add[j] && add[j] == '.' && j-- && i--)
			continue;
		rest += ret[i] + add[j--] - 96;
		ret[i--] = (rest % 10) + '0';
		rest /= 10;
	}
	if (i >= 0 && rest)
		ret[i] += rest;
	else if (rest)
		ret = ft_strjoinfree("1", ret, -1, 3);
	return (ret);
}

/*
** ft_long_sum - prepares nlines before addition
*/

char		*ft_long_sum(char *main, char *add)
{
	char	*main_;
	char	*add_;
	char	*ret;

	if (ft_adot(main) == ft_adot(add))
		return (l_base_sum(main, add, ft_strlen(main) - 1, ft_strlen(add) - 1));
	main_ = (!ft_dot(main)) ?
			ft_strjoinfree(main, ".0", -1, 0) : ft_strdup(main);
	add_ = (!ft_dot(add)) ? ft_strjoinfree(add, ".0", -1, 0) : ft_strdup(add);
	if (ft_adot(main_) < ft_adot(add_))
		main_ = ft_nline(ft_adot(add_) - ft_adot(main_) + 1, main_, 1);
	else
		add_ = ft_nline(ft_adot(main_) - ft_adot(add_) + 1, add_, 1);
	ret = l_base_sum(main_, add_, ft_strlen(main_) - 1, ft_strlen(add_) - 1);
	free(main_);
	free(add_);
	return (ret);
}
