#include <sys/stat.h>
#include "includes/ft_ls.h"

char 	*ls_get_flags(int ac, char **av, size_t *last)
{
	char flags[5];
	size_t i;
	size_t j;

	i = 0;
	ft_memset(flags, '\0', 5);
	while (*last < ac && av[*last][0] == '-')
	{
		j = 0;
		while (av[*last][++j] != '\0')
			if (ft_strchr("aRtlr", av[*last][j]))
			{
				if (!ft_strchr(flags, av[*last][j]))
					flags[i++] = av[*last][j];
			} else
				exit(ft_printf(EFLAG, av[*last][j]));
		(*last)++;
	}
	return (ft_strdup(flags));
}

t_input	*get_files(DIR *dir, size_t *size)
{
	t_input *ret;
	t_input *temp;

	ret = ft_memalloc(sizeof(t_input));
	temp = ret;
	while ((temp->data = readdir(dir)) != NULL)
	{
		temp->next = ft_memalloc(sizeof(t_input));
		temp = temp->next;
		(*size)++;
	}
	temp->next = NULL;
	return (ret);
}

t_files	*get_valid(t_input **raw, size_t *size, const char *flags, char *path)
{
	t_input	*temp;
	t_files	*ret;
	size_t 	i;

	i = 0;
	ret = ft_memalloc(sizeof(t_input) * *size);
	temp = *raw;

	while (temp->data)
	{
		if (temp->data->d_name[0] == '.' && (!flags || !ft_strchr(flags, 'a')))
		{
			temp = temp->next;
			continue;
		}
		ret[i].flags = flags;
		ret[i].path = ft_strjoinfree(path, ft_strjoin("/", temp->data->d_name), -1, 3);
		stat(ret[i].path, ret[i].stat);
		ret[i].dirent = *(temp->data);
		temp = temp->next;
		i++;
	}
	*size = i;
	return (ret);
}

t_files	*sort_files(t_input **raw, size_t *size, const char *flags, char *path)
{
	t_files	*data;

	data = get_valid(raw, size, flags, path);
	_Bool			flag;
	t_files			temp;
	size_t	i;
	size_t	j;

	i = 0;
	while (i++ < *size)
	{
		flag = 1;
		j = 0;
		while (++j < *size)
			if (ft_strcmp(data[j - 1].dirent.d_name, data[j].dirent.d_name))
			{
				flag = 0;
				temp = data[j - 1];
				data[j - 1] = data[j];
				data[j] = temp;
			}
		if (flag)
			break ;
	}
//	comp(ret, *size);
	return data;
}

void	ft_ls(DIR *dir, char *path, const char *flags)
{
	size_t 	i;
	size_t	size;
	t_input	*raw;
	t_files	*files;

	i = 0;
	size = 0;
	raw = get_files(dir, &size);
	files = sort_files(&raw, &size, flags, path);
	while (i < size)
	{
		ft_printf("%s  ", files[i].dirent.d_name);
		i++;
	}
}

int     main(int ac, char **av)
{
	char 	*flags;
	_Bool	prefix;
	DIR 	*curr;
	size_t	last;

	last = 1;
	flags = ls_get_flags(ac, av, &last);

	prefix = (last < ac - 1);
	while (last < ac)
	{
		if ((curr = opendir(av[last])) == NULL && ft_printf(EFILE, av[last]))
			continue ;
		if (prefix)
			ft_printf("%s:\n", av[last]);
		ft_ls(curr, av[last], flags);
		closedir(curr);
	}
	if (ac == 1)
	{
		curr = opendir(".");
		ft_ls(curr, ".", NULL);
		closedir(curr);
	}
	free(flags);

    /*
	while (files = readdir(curr))
	{
		if (files->d_type == 4)
			ft_printf("%s/  ", files->d_name);
		else
			ft_printf("%s  ", files->d_name);
	}

	ft_printf("\n");
	closedir(curr);
	*/
    return (0);
}