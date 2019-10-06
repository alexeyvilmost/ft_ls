/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 18:50:08 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/24 18:13:32 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Initializes and clears the contents, returning a fresh element of t_type.
**
** Инициализирует и подготавливает содержимое, возвращая 'свежий' элемент t_type
*/

static t_type	pf_new_list(void)
{
	t_type		data;

	data.len = 0;
	data.add = 0;
	data.size = 0;
	data.base = 0;
	data.accur = -1;
	data.type = '\0';
	data.spec = '\0';
	data.printed = 0;
	data.line = NULL;
	data.sign = FALSE;
	ft_memset(data.flag, '\0', 3);
	return (data);
}

/*
** pf_type_parser
**
** type fork, removing extra flags, stabilize data.size
** calls the function according to a data.spec and handle 'p'
*/

static size_t	pf_type_parser(t_type data, va_list arg)
{
	if (data.size < 0)
	{
		data.size = ft_abs(data.size);
		data.flag[0] = '-';
	}
	if (data.spec == 'u')
		data.flag[1] = '\0';
	if (data.flag[2] && !ft_strchr("oxXf", data.spec))
		data.flag[2] = '\0';
	if (data.spec == 'c' || data.spec == '%')
		return (pf_put_c(data, arg).printed);
	if (data.spec == 's')
		return (pf_put_s(data, arg).printed);
	if (ft_strchr("diuoxX", data.spec))
		return (pf_put_n(data, arg, 0, 0).printed);
	if (data.spec == 'f')
		return (pf_put_f(data, arg).printed);
	if (data.spec == 'p')
	{
		data.type = 'L';
		data.flag[2] = '#';
		return (pf_put_n(data, arg, 0, 0).printed);
	}
	return (0);
}

/*
** pf_get_spec and pf_get_params fills a main fields of t_type:
** specificator	format : %[flag][size][accur][type][spec]
**
** char		data.flag[3] - cont(ains) flags, with handling mutually exclusive
** 				data.flag[0] may be (sorted by priority) '-','0' or '\0'
** 	data.flag[1] may be (as before) '+',' ' or '\0'
** 	data.flag[2] may be '#' or '\0' (only needed for "oxXp" spec)
** size_t	data.size - cont needed field-width for this value
** size_t	data.accur - cont accur for "f" and min symbol must be displayed
** char		data.type - cont type size spec(ificator) possible value: "lhLH"
** char		data.spec - cont type spec, possible value: "diouxXpcsf"
*/

static t_type	pf_get_params(t_cchar s, size_t *i, t_type data, va_list arg)
{
	if (s[*i] && s[*i] == '*' && (*i)++)
		data.size = va_arg(arg, int);
	if (s[*i] && ft_isdigit(s[*i]))
	{
		data.size = ft_atoi(&s[*i]);
		while (s[*i] && ft_isdigit(s[*i]))
			(*i)++;
	}
	if (s[*i] && s[*i] == '.' && s[++(*i)])
	{
		if (ft_isdigit(s[*i]))
			data.accur = ft_atoi(&s[*i]);
		else if (s[*i] == '*' && ++(*i))
			data.accur = va_arg(arg, int);
		else if (s[*i])
			data.accur = 0;
		while (s[*i] && ft_isdigit(s[*i]))
			++(*i);
	}
	if (s[*i] && ft_strchr("hlLz", s[*i]))
		data.type = s[(*i)++];
	if (s[*i] && ft_strchr("hlLz", s[*i]) && (s[*i] == s[*i - 1]))
		data.type -= 32 + (++(*i) * 0);
	return (data);
}

static int		pf_get_spec(const char *s, size_t *i, va_list arg, size_t *pr)
{
	t_type		data;

	++(*i);
	data = pf_new_list();
	while (s[*i] && ft_strchr("-+ 0#", s[*i]))
	{
		if (ft_strchr("-0", s[*i]) && data.flag[0] != '-')
			data.flag[0] = s[*i];
		else if (ft_strchr("+ ", s[*i]) && data.flag[1] != '+')
			data.flag[1] = s[*i];
		else if (s[*i] == '#' && data.flag[2] != '#')
			data.flag[2] = s[*i];
		(*i)++;
	}
	data = pf_get_params(s, i, data, arg);
	if (!(s[*i] && ft_strchr("cspdiouxXf%", s[*i])))
		return (FALSE);
	data.spec = s[*i];
	*pr += pf_type_parser(data, arg);
	pf_fill_n(data, arg, *pr);
	(*i)++;
	return (TRUE);
}

int				ft_printf(const char *format, ...)
{
	size_t	i;
	int		j;
	va_list args;
	size_t	printed;

	i = 0;
	printed = 0;
	if (!format)
		return (0);
	va_start(args, format);
	while ((j = ft_strfchr(&format[i], '%')) != -1)
	{
		printed += write(1, &format[i], j);
		i += j;
		pf_get_spec(format, &i, args, &printed);
	}
	printed += write(1, &format[i], ft_strlen(format) - i);
	va_end(args);
	return (printed);
}
