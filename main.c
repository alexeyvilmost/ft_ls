#include <sys/stat.h>
#include <stdio.h>
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

t_input	*get_files(DIR *dir, size_t *size, size_t *max_len)
{
	t_input *ret;
	t_input *temp;

	ret = ft_memalloc(sizeof(t_input));
	temp = ret;
	while ((temp->data = readdir(dir)) != NULL)
	{
		if (ft_strlen(temp->data->d_name) > *max_len)
			*max_len = ft_strlen(temp->data->d_name);
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
		ret[0].path[0] = '\0';
		ft_strcat(ret[i].path, path);
		ft_strcat(ret[i].path, "/");
		ft_strcat(ret[i].path, temp->data->d_name);
		lstat(ret[i].path, &ret[i].stat);
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
	size_t			i;
	size_t			j;

	comp(data, *size, flags);
	return data;
}

void	ft_ls(DIR *dir, char *path, const char *flags)
{
	size_t 	i;
	size_t	size;
	size_t	max_len;
	t_input	*raw;
	t_files	*files;

	i = 0;
	size = 0;
	max_len = 0;
	raw = get_files(dir, &size, &max_len);
	max_len += (8 - (max_len + 2) % 8) + 2;
	files = sort_files(&raw, &size, flags, path);
	while (i < size)
	{
		ft_printf("%-*s", (int)max_len, files[i].dirent.d_name);
		i++;
	}
	free(raw);
	free(files);
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
	if (last == ac) // TODO: incorrect condition
	{
		curr = opendir(".");
		ft_ls(curr, ".", flags);
		closedir(curr);
		ft_printf("\n");
	}
	while (last < ac)
	{
		if ((curr = opendir(av[last])) == NULL && ft_printf(EFILE, av[last]))
			continue ;
		if (prefix)
			ft_printf("%s:\n", av[last]);
		ft_ls(curr, av[last], flags);
		closedir(curr);
		last++;
		ft_printf("\n");
		if (prefix && last < ac)
			ft_printf("\n");
	}
	free(flags);

    return (0);
}