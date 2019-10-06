/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_diff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 02:37:37 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/26 02:25:12 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** l_base_diff - substuct one nline form the other by column substruct algo
*/

static char	*l_base_diff(char *main, char *diff, t_llong i, t_llong j)
{
	char	rest;
	char	*ret;

	rest = 0;
	if (ft_longcmp(main, diff) < 0)
		return (l_base_diff(diff, main, j, i));
	ret = ft_strdup(main);
	while (i >= 0 && j >= 0)
	{
		(diff[j] == '.') ? i -= (j-- * 0) + 1 : 0;
		rest = ret[i] - diff[j] - rest;
		if (ret[i] < diff[j] || (ret[i] == diff[j] && rest < 0))
			rest += 20;
		ret[i--] = rest % 10 + '0';
		j--;
		rest /= 10;
	}
	if (rest && i >= 0)
		ret[i]--;
	return (ret);
}

/*
** ft_long_diff - prepare nlines before calling function l_base_diff
** TODO: bad indentation
*/

char		*ft_long_diff(char *main, char *add)
{
	char	*main_;
	char	*add_;
	char	*ret_;

	if (ft_adot(main) == ft_adot(add))
	{
		return (l_base_diff(main, add,
				ft_strlen(main) - 1, ft_strlen(add) - 1));
	}
	main_ = (!ft_dot(main)) ?
			ft_strjoinfree(main, ".0", -1, 0) : ft_strdup(main);
	add_ = (!ft_dot(add)) ? ft_strjoinfree(add, ".0", -1, 0) : ft_strdup(add);
	if (ft_adot(main_) < ft_adot(add_))
		main_ = ft_nline(ft_adot(add_) - ft_adot(main_) + 1, main_, 1);
	else
		add_ = ft_nline(ft_adot(main_) - ft_adot(add_) + 1, add_, 1);
	ret_ = l_base_diff(main_, add_,
			ft_strlen(main_) - 1, ft_strlen(add_) - 1);
	free(main_);
	free(add_);
	return (ret_);
}
