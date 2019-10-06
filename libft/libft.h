/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:42:22 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/31 15:20:02 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>

/*
** ==========================# My definitions #=================================
*/

# define TRUE 1
# define FALSE 0
# define ERROR -1

typedef long double				t_ldouble;
typedef const char*				t_cchar;
typedef long long int			t_llong;
typedef unsigned long int		t_ulong;
typedef unsigned long long int	t_ullong;
typedef unsigned short int		t_ushort;
typedef unsigned int			t_uint;
typedef unsigned char			t_uchar;
typedef long double				t_dbl;

/*
** ==============================# My funcs: #==================================
**
** ft_abs - returns absolute value of int
** ft_pow - raise number to a power
** ft_strrev - replace input string to a reversed version
** ft_strfchr - returns the position of first matching symbol
*/

t_ullong			ft_abs(long long n);
char				*ft_get(int amount, int symbol);
t_llong				ft_pow(t_llong to_raise, short power);
long double			ft_pow_dbl(long double to_raise, short power);
t_llong				ft_max(t_llong first_num, t_llong second_num);
t_llong				ft_min(t_llong first_num, t_llong second_num);
char				*ft_itoa_base(t_ullong num, t_ushort base, char letter);

_Bool				ft_isspace(char c);
_Bool				ft_isupper(int chr);
_Bool				ft_islower(int chr);

void				*ft_memsetloc(size_t size, int val);

short				ft_nsize(t_ullong n);
short				ft_nsize_base(t_ullong n, short base);
t_ullong			ft_nmult(t_ullong n);
t_ullong			ft_nmult_base(t_ullong n, short base);

char				*ft_strrev(const char *str);
int					ft_strfchr(const char *str, int to_find);
char				*ft_strerase(t_cchar to_erase, int start_pos, int size);
char				*ft_strjoinfree(char *s1, char *s2, t_llong am, char to_f);

/*
** ========================# Long math on strings #=============================
*/

size_t				ft_dot(const char *str);
size_t				ft_adot(const char *str);
char				*ft_biline(int power);
int					ft_longcmp(const char *n1, const char *n2);
char				*ft_nline(int pos, char *num, _Bool to_free);
char				*ft_rm_dot(char	*str, _Bool to_free);
char				*ft_put_dot(char *str, size_t where, _Bool to_free);

char				*ft_long_mult(char *fst, char *snd);
char				*ft_long_sum(char *main, char *add);
char				*ft_long_diff(char *main, char *diff);
char				*ft_long_div(char *first, char *second, short accur);
char				*ft_long(char *f_num, char *s_num, char option, short to_f);

/*
** =============================# get_next_line #===============================
*/

# define BUFF_SIZE 32

int					get_next_line(const int fd, char **line);

/*
** ==============================# ft_printf #==================================
*/

# define B23 63
# define B127 16383
# define USIGN "uoxXp"
# define O '0'

typedef struct		s_type
{
	char			flag[3];
	int				size;
	int				accur;
	char			type;
	char			spec;
	char			*line;
	short			base;
	_Bool			sign;
	short			add;
	size_t			len;
	size_t			printed;
}					t_type;

typedef	union
{
	long double		main;
	struct
	{
		t_ulong		mant : 63;
		t_ushort	expo : 15;
		_Bool		sign : 1;
	}				memory;
}					t_double;

int					ft_printf(const char *format, ...);
t_type				pf_put_c(t_type data, va_list arg);
t_type				pf_put_s(t_type data, va_list arg);
t_type				pf_put_f(t_type data, va_list arg);
t_type				pf_put_n(t_type data, va_list arg, t_llong i, t_ullong n);
void				pf_fill_n(t_type data, va_list arg, int printed);
char				*pf_double_line(t_double db, int accur);
t_type				pf_pre_put(t_type data, _Bool sign);
size_t				pf_write(int symbol, size_t amount);

/*
** =======================# Standard functions: #===============================
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_atoi(t_cchar str);

int					ft_isalnum(int ch);
int					ft_isalpha(int ch);
int					ft_isascii(int ch);
int					ft_isdigit(int ch);
int					ft_isprint(int ch);

char				*ft_itoa(t_llong n);

void				ft_bzero(void *point, size_t size);

int					ft_memcmp(const void *mem1, const void *mem2, size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t size);
void				*ft_memalloc(size_t size);
void				*ft_memcpy(void *dest, const void *src, size_t size);
void				*ft_memset(void *point, int val, size_t size);
void				*ft_memchr(const void *arr, int to_find, size_t size);
void				*ft_memmove(void *dest, const void *src, size_t size);
void				ft_memdel(void **ap);

void				ft_putnbr(int n);
void				ft_putchar(char c);
void				ft_putstr(t_cchar s);
void				ft_putendl(t_cchar s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(t_cchar s, int fd);
void				ft_putendl_fd(t_cchar s, int fd);

int					ft_strcmp(t_cchar s1, t_cchar s2);
int					ft_strncmp(t_cchar s1, t_cchar s2, size_t size);
int					ft_strequ(t_cchar s, t_cchar s2);
int					ft_strnequ(t_cchar s1, t_cchar s2, size_t n);
char				*ft_strchr(t_cchar str, int to_find);
char				*ft_strrchr(t_cchar str, int to_find);
char				*ft_strcat(char *dest, t_cchar add);
char				*ft_strncat(char *dest, t_cchar add, size_t size);
char				*ft_strcpy(char *dest, t_cchar src);
char				*ft_strncpy(char *dest, t_cchar src, size_t size);
char				*ft_strmap(t_cchar s, char (*f)(char));
char				*ft_strmapi(t_cchar s, char (*f)(unsigned int, char));
char				*ft_strnew(size_t size);
char				*ft_strstr(t_cchar s1, t_cchar s2);
char				*ft_strnstr(t_cchar s1, t_cchar s2, size_t size);
char				*ft_strsub(t_cchar s1, unsigned int start, size_t len);
char				*ft_strtrim(t_cchar s);
char				**ft_strsplit(t_cchar s1, char c);
char				*ft_strdup(t_cchar src);
char				*ft_strjoin(t_cchar s1, t_cchar s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_strclr(char *s);
void				ft_strdel(char **as);
size_t				ft_strlcat(char *dest, t_cchar stc, size_t size);
size_t				ft_strlen(t_cchar str);

int					ft_toupper(int ch);
int					ft_tolower(int ch);

void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);

#endif
