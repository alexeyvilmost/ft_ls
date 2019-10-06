//
// Created by alexeyvilmost on 06.10.2019.
//
#include <sys/stat.h>
#include "includes/ft_ls.h"

void	common_sort(t_files *data, size_t size, _Bool (*comp)(t_files, t_files))
{
	_Bool			flag;
	t_files			temp;
	size_t	i;
	size_t	j;

	i = 0;
	while (i++ < size)
	{
		flag = 1;
		j = 0;
		while (++j < size)
			if (comp(data[j - 1], data[j]))
			{
				flag = 0;
				temp = data[j - 1];
				data[j - 1] = data[j];
				data[j] = temp;
			}
		if (flag)
			break ;
	}
}