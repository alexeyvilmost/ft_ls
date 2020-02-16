#include "includes/ft_ls.h"

void	print_chmod(mode_t file)
{
	if (S_ISDIR(file))
		ft_printf("d");
	else if (S_ISLNK(file))
		ft_printf("l");
	else
		ft_printf("-");
	ft_printf((file & S_IRUSR) ? "r" : "-");
	ft_printf((file & S_IWUSR) ? "w" : "-");
	ft_printf((file & S_IXUSR) ? "x" : "-");
	ft_printf((file & S_IRGRP) ? "r" : "-");
	ft_printf((file & S_IWGRP) ? "w" : "-");
	ft_printf((file & S_IXGRP) ? "x" : "-");
	ft_printf((file & S_IROTH) ? "r" : "-");
	ft_printf((file & S_IWOTH) ? "w" : "-");
	ft_printf((file & S_IXOTH) ? "x " : "- ");
}

void	print_full(t_files file, t_dir dir, const char *flags)
{
	char 	link[PATH_MAX];

	print_chmod(file.stat.st_mode);
	ft_printf("%*d ", dir.maxlink + 1, file.stat.st_nlink);
	ft_printf("%-*s ", dir.maxuser + 1, getpwuid(file.stat.st_uid)->pw_name);
	ft_printf("%-*s ", dir.maxgroup + 1, getgrgid(file.stat.st_gid)->gr_name);
	ft_printf("%*d ", dir.maxblock, file.stat.st_size);
	char *time = ctime(&file.stat.st_mtimespec.tv_sec);
	ft_printf("%.12s ", &time[4]);
	ft_printf("%s", file.dirent.d_name);
	if (S_ISLNK(file.stat.st_mode) && ft_strchr(flags, 'l'))
	{
		readlink(file.path, link, PATH_MAX);
		ft_printf(" -> %s", link);
	}
	ft_printf("\n");
}

t_dir	get_maxes(t_files *files, size_t size)
{
	size_t		i;
	t_dir		result;
	struct stat *curr;

	result.maxblock = 0;
	result.maxgroup = 0;
	result.maxuser = 0;
	result.maxlink = 0;
	result.maxname = 0;
	result.total = 0;
	i = 0;
	while (i < size)
	{
		curr = &files[i].stat;
		result.maxlink = MAX(result.maxlink, (size_t)ft_nsize(curr->st_nlink));
		result.maxuser = MAX(result.maxuser,
							 ft_strlen(getpwuid(curr->st_uid)->pw_name));
		result.maxgroup = MAX(result.maxgroup,
							  ft_strlen(getgrgid(curr->st_gid)->gr_name));
		result.maxblock = MAX(result.maxblock, (size_t)ft_nsize(curr->st_size));
		result.total += files[i].stat.st_blocks;
		result.maxname = MAX(result.maxname, ft_strlen(files[i++].path));
	}
	result.maxname += (8 - (result.maxname + 2) % 8) + 2;
	return result;
}

void	print_ls(t_files *files, size_t size, const char *flags)
{
	t_dir	dir_info;
	size_t	i;

	i = 0;
	dir_info = get_maxes(files, size);
	if (ft_strchr(flags, 'l'))
		ft_printf("total %d\n", dir_info.total);
	while (i < size)
	{
		if (ft_strchr(flags, 'l'))
			print_full(files[i], dir_info, flags);
		else
			ft_printf("%-*s", (int)dir_info.maxname, files[i].dirent.d_name);
		i++;
	}
	if (!ft_strchr(flags, 'l'))
		ft_printf("\n");
}