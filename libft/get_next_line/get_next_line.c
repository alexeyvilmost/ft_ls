/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 05:53:16 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/31 15:25:40 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*gnl_ultjoin(char *s1, char *s2, int amount)
{
	char	*new;

	if (!amount || (!*s1 && !*s2))
	{
		new = ft_strdup(s1);
		free(s1);
		return (new);
	}
	if (!s1 || !s2 ||
		!(new = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	if (amount != -1)
		ft_strncat(ft_strcat(new, s1), s2, amount);
	else
		ft_strcat(ft_strcat(new, s1), s2);
	free(s1);
	return (new);
}

static int		find_nl(char **new, char *buff, int mode)
{
	int	n;

	if (!buff || !*buff)
		return (-1);
	n = 0;
	while (buff[n] != '\n' && buff[n])
		n++;
	if (n == BUFF_SIZE || !buff[n])
		n = -1;
	if (mode)
		return (n);
	if (n != -1)
		return (n);
	*new = ft_strcat(*new, buff);
	ft_memset(buff, '\0', BUFF_SIZE + 1);
	return (-1);
}

static int		gnl_return(char **line, char *new, int n, char *f)
{
	int	i;

	new = gnl_ultjoin(new, f, n);
	i = 0;
	while (n != -1 && n <= BUFF_SIZE)
		f[i++] = f[++n];
	if (n == -1 && new && !new[0])
	{
		free(new);
		return (0);
	}
	*line = ft_strdup(new);
	free(new);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char			*new;
	static char		f[12000][BUFF_SIZE + 1];
	int				n;

	if (fd < 0 || read(fd, NULL, 0) < 0 || !line
			|| BUFF_SIZE + 1 == 0 || !(new = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (!f[fd][0])
		ft_memset(f[fd], '\0', BUFF_SIZE + 1);
	if ((n = find_nl(&new, f[fd], 0)) == -1)
		while (read(fd, f[fd], BUFF_SIZE) > 0 &&
				(n = find_nl(&new, f[fd], 1)) == -1)
		{
			new = gnl_ultjoin(new, f[fd], -1);
			ft_strclr(f[fd]);
		}
	return (gnl_return(line, new, n, f[fd]));
}
