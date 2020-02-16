#include "includes/ft_ls.h"

char 	*ls_get_flags(int ac, char **av, int *last)
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

	*size = 0;
	ret = ft_memalloc(sizeof(t_input));
	temp = ret;
	while ((temp->data = readdir(dir)) != NULL)
	{
//		ft_printf("Pre-pre-pre-pre: %s\n", temp->data->d_name);
		temp->next = ft_memalloc(sizeof(t_input));
		temp = temp->next;
		(*size)++;
	}
	temp->next = NULL;
	temp = ret;
	while (temp->data)
	{
//		ft_printf("Pre-pre-pre: %s\n", temp->data->d_name);
		temp = temp->next;
	}
	return (ret);
}

void	recursive_ls(t_files *files, size_t size, const char *flags)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		if (S_ISDIR(files[i].stat.st_mode) && ft_strcmp(files[i].path, ".")
			&& ft_strcmp(files[i].path, ".."))
		{
			ft_printf("\n%s:\n", files[i].path);
			if (ft_ls(files[i].path, flags))
			{
				ft_printf("Error on: %s\n", files[i].path);
				continue ;
			}
		}
		i++;
	}
}

int	ft_ls(char *path, const char *flags)
{
	size_t	size;
	t_files	*files;
	DIR		*curr;

	size = 0;
	if ((curr = opendir(path)) == NULL)
		return (-1);
	files = sort_files(get_files(curr, &size), &size, flags, path);
//	for (int i = 0; i < size; i++)
//		ft_printf("%s\n", files[i].path);
	print_ls(files, size, flags);
	if (ft_strchr(flags, 'R'))
		recursive_ls(files, size, flags);
	free(files);
	closedir(curr);
	return (0);
}

int     main(int ac, char **av)
{
	char 	*flags;
	_Bool	prefix;
	int	last;

	last = 1;
	flags = ls_get_flags(ac, av, &last);

	prefix = (last < ac - 1);
	if (last == ac) // TODO: incorrect condition
		ft_ls(".", flags);
	while (last < ac)
	{
		if (prefix)
			ft_printf("%s:\n", av[last]);
		ft_ls(av[last++], flags);
		if (prefix && last < ac)
			ft_printf("\n");
	}
	free(flags);

    return (0);
}