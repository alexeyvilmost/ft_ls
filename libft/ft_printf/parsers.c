/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 21:02:31 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/31 15:15:45 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Main int fork, deciding which function to send data for processing
**
** Главная развилка целых чисел, решающая, в какую функцию отправить для
** обработки
*/

t_type	pf_put_n(t_type data, va_list arg, t_llong i, t_ullong n)
{
	if (data.type == 'L')
		n = ft_strchr(USIGN, data.spec) ? va_arg(arg, t_ullong)
				: ft_abs(i = va_arg(arg, t_llong));
	else if (data.type == 'l' || data.type == 'z')
		n = ft_strchr(USIGN, data.spec) ? va_arg(arg, t_ullong) :
				ft_abs(i = va_arg(arg, long long));
	else if (data.type == 'H')
		n = ft_strchr(USIGN, data.spec) ? (t_uchar)va_arg(arg, int) :
			ft_abs(i = (char)va_arg(arg, int));
	else if (data.type == 'h')
		n = ft_strchr(USIGN, data.spec) ? (t_ushort)va_arg(arg, int) :
				ft_abs(i = (short)va_arg(arg, int));
	else
		n = ft_strchr(USIGN, data.spec) ? va_arg(arg, t_uint) :
			ft_abs(i = va_arg(arg, int));
	if (ft_strchr("oxXp", data.spec))
		data.base = (data.spec == 'o') ? 8 : 16;
	data.line = (!n && !data.accur) ? ft_strnew(0) :
			ft_itoa_base(n, data.base, data.spec);
	return (pf_pre_put(data, ft_strchr(USIGN, data.spec) ? 0 : (i < 0)));
}

t_type	pf_put_f(t_type data, va_list arg)
{
	int			accur;
	t_double	db;

	accur = (data.accur == -1) ? 6 : data.accur;
	db.main = (data.type == 'L') ? va_arg(arg, t_ldouble) : va_arg(arg, double);
	data.line = pf_double_line(db, accur);
	if (accur == 0 && !data.flag[2])
		data.line[ft_dot(data.line)] = '\0';
	return (pf_pre_put(data, db.memory.sign));
}

t_type	pf_put_s(t_type data, va_list arg)
{
	size_t	size;

	data.line = va_arg(arg, char*);
	if (!data.line)
		data.line = ft_strdup("(null)");
	else
		data.line = ft_strdup(data.line);
	if (data.accur >= 0 && data.accur < (int)ft_strlen(data.line))
		data.line = ft_strsub(data.line, 0, data.accur);
	size = ft_strlen(data.line);
	if (data.size > (int)size && data.flag[0] != '-')
		data.printed += pf_write(' ', data.size - size);
	ft_putstr(data.line);
	data.printed += ft_strlen(data.line);
	free(data.line);
	if (data.size > (int)size && data.flag[0] == '-')
		data.printed += pf_write(' ', data.size - size);
	return (data);
}

t_type	pf_put_c(t_type data, va_list arg)
{
	char	chr;
	size_t	size;

	chr = (data.spec == 'c') ? va_arg(arg, int) : '%';
	size = (data.size > 1) ? data.size : 1;
	data.line = ft_strnew(size);
	if (data.flag[0] == '0')
		ft_memset(data.line, '0', size);
	else
		ft_memset(data.line, ' ', size);
	if ((size > 1 && data.flag[0] == '-') || size == 1)
		data.line[0] = chr;
	else
		data.line[data.size - 1] = chr;
	write(1, data.line, size);
	data.printed += size;
	free(data.line);
	return (data);
}

void	pf_fill_n(t_type data, va_list arg, int printed)
{
	if (data.spec != 'n')
		return ;
	if (!data.type)
		*va_arg(arg, int *) = printed;
	else if (data.type == 'l')
		*va_arg(arg, long *) = printed;
	else if (data.type == 'L')
		*va_arg(arg, t_llong*) = printed;
	else if (data.type == 'h')
		*va_arg(arg, short *) = printed;
	else if (data.spec == 'H')
		*va_arg(arg, char *) = printed;
	else if (data.spec == 'z')
		*va_arg(arg, size_t *) = printed;
}
