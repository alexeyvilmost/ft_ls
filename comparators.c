//
// Created by alexeyvilmost on 06.10.2019.
//

#include <sys/stat.h>
#include "includes/ft_ls.h"

static _Bool	default_comparator(t_files a, t_files b)
{
	int i;
	char c1;
	char c2;

	i = 0;
	while (a.dirent.d_name[i] == b.dirent.d_name[i])
		i++;
	c1 = a.dirent.d_name[i];
	c2 = b.dirent.d_name[i];
	if (ft_isupper(c1) && ft_islower(c2))
		return (FALSE);
	if (ft_islower(c1) && ft_isupper(c2))
		return (TRUE);
	return (c1 > c2);
}

static _Bool	rdefault_comparator(t_files a, t_files b)
{
	return !default_comparator(a, b);
}

static _Bool	time_comparator(t_files a, t_files b)
{
	if (a.stat.st_ctimespec.tv_sec == b.stat.st_ctimespec.tv_sec)
		return default_comparator(a, b);
	return a.stat.st_ctimespec.tv_sec < b.stat.st_ctimespec.tv_sec;
}

static _Bool	rtime_comparator(t_files a, t_files b)
{
	return !time_comparator(a, b);
}

void	comp(t_files *data, size_t size, const char *flags)
{
	if (!flags)
		return common_sort(data, size, default_comparator);
	if (ft_strchr(flags, 't'))
	{
		if (ft_strchr(flags, 'r'))
			return common_sort(data, size, rtime_comparator);
		else
			return common_sort(data, size, time_comparator);
	}
	else
	if (strchr(flags, 'r'))
		return common_sort(data, size, rdefault_comparator);
	else
		return common_sort(data, size, default_comparator);
}
