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

size_t	count_files(char const *dirname, _Bool a_param)
{
	size_t			result;
	struct dirent	*temp;
	DIR 			*dir;

	result = 0;
	if (!(dir = opendir(dirname)))
		return 0;
	while (dir && (temp = readdir(dir)))
		if (temp->d_name[0] != '.' || a_param)
			result++;

	closedir(dir);
	return result;
}

void	recursive_ls(t_files *files, size_t size, const char *flags)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		if (S_ISDIR(files[i].stat.st_mode) &&
		ft_strcmp(files[i].dirent.d_name, ".") &&
		ft_strcmp(files[i].dirent.d_name, ".."))
		{
			ft_printf("\n%s:\n", files[i].path);
			if (files[i].stat.st_mode & S_IROTH)
			{
				if (ft_ls(files[i].path, flags))
					ft_printf("Error on: %s\n", files[i].path);
			}
			else
				ft_printf("ls: %s: Permission denied\n", files[i].dirent.d_name);
		}
		i++;
	}
}

void	parse_error(char *path)
{
	char	*trim;
//	DIR		*parent_dir;

	if ((trim = ft_strrchr(path, '/')) != &path[0])
	{
		*trim = '\0';
	}
}

int	ft_ls(char *path, const char *flags)
{
	size_t	size;
	t_files	*files;
	DIR		*curr;

	size = count_files(path, ft_strchr(flags, 'a'));
	if ((curr = opendir(path)) == NULL)
	{
		parse_error(path);
		return (-1);
	}
	files = sort_files(curr, size, flags, path);
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