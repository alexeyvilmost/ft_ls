//
// Created by alexeyvilmost on 06.10.2019.
//

#ifndef FT_LS_H
# define FT_LS_H

# define EFLAG "ls: incorrect key - %c\n"
# define EFILE "ls: don't have access to a %s: No file or directory match\n"

# include "../libft/libft.h"
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <sys/stat.h>
# include <stdio.h>
# include <time.h>
# include <sys/param.h>

typedef struct dirent t_d;

typedef struct			s_rawdata
{
	struct s_rawdata	*next;
	struct dirent		*data;
}						t_input;

typedef struct			s_file
{
	struct dirent		dirent;
	struct stat			stat;
	char				path[PATH_MAX];
}						t_files;

typedef struct 			s_dir
{
	size_t				maxname;
	size_t 				maxuser;
	size_t 				maxgroup;
	size_t				maxblock;
	size_t				maxlink;
	size_t				total;
}						t_dir;

int		ft_ls(char *path, const char *flags);
void	print_ls(t_files *files, size_t size, const char *flags);
void	common_sort(t_files *data, size_t size, _Bool (*comp)(t_files, t_files));
t_files	*sort_files(DIR *dir, size_t size, const char *flags, char *path);
void	comp(t_files *data, size_t size, const char *flags);

# endif