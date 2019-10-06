/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 20:51:28 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/31 15:15:45 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Prints to a standart output (amount) number of (symbol)s.
**
** Печатает в стандартный вывод (amount) (symbol)ов
*/

size_t			pf_write(int symbol, size_t amount)
{
	char	*ret;

	ret = ft_strnew(amount);
	ft_memset(ret, symbol, amount);
	write(1, ret, amount);
	free(ret);
	return (amount);
}

/*
** Print necessary characters depending on data (flag; size; accur) options with
** a number, presented as NULL-terminated string;
**
** Печатает число, предстaвленное в виде строки, оканчивающейся \0, а также
** необходимые символы, в зависимости от представленных в data опций
*/

static t_type	pf_put(t_type d, t_llong size, short f)
{
	f = ((int)d.len > d.accur || d.accur < 0) ? 0 :
		(size = d.accur);
	if ((size = d.size - size) > d.add &&
			(!d.flag[0] || (d.flag[0] == O && d.accur != -1 && d.spec != 'f')))
		d.printed += pf_write(' ', size - d.add);
	if (d.sign)
		d.printed += write(1, "-", 1);
	else if (d.flag[1])
		d.printed += write(1, &d.flag[1], 1);
	if (d.flag[2] == '#' && d.spec == 'o' && ft_strcmp(d.line, "0"))
		d.printed += write(1, "0", 1);
	else if (d.spec == 'p')
		d.printed += write(1, "0x", 2);
	else if (d.flag[2] == '#' && ft_strcmp(d.line, "0") && d.line[0])
		d.printed += write(1, d.spec == 'x' ? "0x" : "0X", 2);
	if (size > d.add && d.flag[0] == O && (d.accur < 0 || d.spec == 'f'))
		d.printed += pf_write(O, size - d.add);
	d.printed += (f) ? pf_write(O, f - d.len) : 0;
	d.printed += write(1, d.line, ft_strlen(d.line));
	free(d.line);
	d.printed += (size > d.add && d.flag[0] == '-') ?
			pf_write(' ', size - d.add) : 0;
	return (d);
}

/*
** prepares data elems before calling fuction pf_put
*/

t_type			pf_pre_put(t_type data, _Bool neg)
{
	data.sign = neg;
	if (data.len != 1)
		data.len = ft_strlen(data.line);
	data.add += (data.flag[1] || data.sign);
	if (!ft_strchr("oxXp", data.spec))
		data.flag[2] = '\0';
	if (!data.flag[2])
		return (pf_put(data, data.len, 0));
	if (data.spec == 'o' && ft_strcmp(data.line, "0"))
		data.len++;
	else if (data.spec == 'p')
		data.add += 2;
	else if (ft_strcmp(data.line, "0") && data.line[0])
		data.add += 2;
	return (pf_put(data, data.len, 0));
}

/*
** pf_double_line works similar to itoa - takes db (union for memory parsing)
** and returnes line as NULL-terminated string representation
*/

char			*pf_double_line(t_double db, int accur)
{
	char		*ret;
	char		*buff;
	const short	power = db.memory.expo - B127;

	if (db.memory.mant)
		ret = ft_long(ft_itoa(db.memory.mant),
				ft_biline(B23 - power), '/', -accur - 1);
	else
		ret = ft_nline(-accur - 1, "0", 0);
	if (power > 0)
		ret = ft_long(ret, ft_itoa(ft_pow(2, power)), '+', 2);
	else
	{
		if (db.memory.expo)
			buff = ft_long(ft_strdup("1"), ft_biline(-power), '/', power);
		else
			buff = ft_strdup("0.0");
		ret = ft_long(ret, buff, '+', 2);
	}
	if (ret[accur + ft_dot(ret) + 1] > '4')
		ret = ft_long(ret, ft_nline(-accur, "1", 0), '+', 2);
	ret[accur + ft_dot(ret) + 1] = '\0';
	return (ret);
}
