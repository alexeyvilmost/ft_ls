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

void	get_path(char full_path[PATH_MAX], char *path, char* filename)
{
	int i;

	i = 0;
//	ft_printf("Raw: %s\n", filename);
	while (path[i] && i < PATH_MAX)
	{
		full_path[i] = path[i];
		i++;
	}
	full_path[i++] = '/';
	while (*filename && i < PATH_MAX)
		full_path[i++] = *filename++;
//	ft_printf("Add: %s\n", full_path);
}

t_files	*get_valid(DIR *dir, size_t size, const char *flags, char *path)
{
	const _Bool		a_param = ft_strchr(flags, 'a');
	struct dirent	*temp;
	t_files			*ret;
	size_t 			i;

	i = 0;
	ret = ft_memalloc(sizeof(t_files) * size);
	if (!ret)
		return NULL;

	while ((temp = readdir(dir)))
	{
		if (temp->d_name[0] == '.' && !a_param)
			continue;
//		ft_printf("Pre: %s\n", temp->data->d_name);
		get_path(ret[i].path, path, temp->d_name);
		lstat(ret[i].path, &ret[i].stat);
		ret[i++].dirent = *temp;
	}
	return (ret);
}

void		free_raw(t_input *raw)
{
	if (raw->next)
		free_raw(raw->next);
	free(raw);
}

t_files	*sort_files(DIR *dir, size_t size, const char *flags, char *path)
{
	t_files	*data;
//
//	temp = raw;
//	while (temp->data)
//	{
//		ft_printf("Pre-pre: %s\n", temp->data->d_name);
//		temp = temp->next;
//	}
	data = get_valid(dir, size, flags, path);
	comp(data, size, flags);
	return data;
}