//
// Created by alexeyvilmost on 06.10.2019.
//

#ifndef FT_LS_H
# define FT_LS_H

# define PATH_MAX 4096
# define EFLAG "ls: incorrect key - %c\n"
# define EFILE "ls: don't have access to a %s: No file or directory match\n"

# include "../libft/libft.h"
# include <dirent.h>

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

void	common_sort(t_files *data, size_t size, _Bool (*comp)(t_files, t_files));
void	comp(t_files *data, size_t size, const char *flags);

# endif
