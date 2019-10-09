//
// Created by alexeyvilmost on 06.10.2019.
//

#include <sys/stat.h>
#include "includes/ft_ls.h"

static _Bool	default_comparator(t_files a, t_files b)
{
	return ft_strcmp(a.dirent.d_name, b.dirent.d_name);
}

static _Bool	rdefault_comparator(t_files a, t_files b)
{
	return !default_comparator(a, b);
}
/*
static _Bool	time_comparator(t_files a, t_files b)
{
	return a.stat->st_ctim.tv_sec > b.stat->st_ctim.tv_sec;
}

static _Bool	rtime_comparator(t_files a, t_files b)
{
	return !time_comparator(a, b);
}
*/
void	comp(t_files *data, size_t size, const char *flags)
{
	if (flags)
		return common_sort(data, size, default_comparator);
/*	if (ft_strchr(data[0].flags, 't'))
	{
		if (ft_strchr(data[0].flags, 'r'))
			return common_sort(data, size, rtime_comparator);
		else
			return common_sort(data, size, time_comparator);
	}
	else */
	if (ft_strchr(flags, 'r'))
		return common_sort(data, size, rdefault_comparator);
	else
		return common_sort(data, size, default_comparator);
}
