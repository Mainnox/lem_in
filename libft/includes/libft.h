/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:32:32 by akremer           #+#    #+#             */
/*   Updated: 2019/11/14 06:05:15 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_tabchr(int *tab, int rififi, int limit);
int					ft_tabcmp(int *tab, int *tab2, int limit);
void				ft_tabcpy(int *src, int *dest, int limit);
char				**ft_split_whitespace(char *str);
void				ft_freesplit(char **split);
int					ft_splitlen(char **white);
int					ft_strcount(char *str, char c);
int					ft_nbrlen_clas(int nb);
int					ft_tablen(int *tab, int stop);
int					ft_nbrlen(unsigned long long n,
		char signe, unsigned int ba);
void				*ft_realloc(void *ptr, size_t size);
int					ft_strclen(const char *str, char c);
char				*ft_strcsub(const char *src, char c);
int					ft_atoi(const char *str);
void				ft_putstr(const char *str);
void				ft_putchar(char c);
void				*ft_memset(void	*str, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
size_t				ft_strlen(const char *str);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
char				*ft_strdup(const char *str);
void				ft_intrev(int *tab, size_t size);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memalloc(size_t n);
void				ft_memdel(void **ap);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *str, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
int					ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *src, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f) (unsigned int, char));
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t n);
char				*ft_strnstr(const char *str, const char *to_find, size_t n);
char				*ft_strrchr(const char *str, int c);
char				*ft_strstr(const char *s, const char *to);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_bzero(void *s, size_t n);
void				ft_strrev(char *str);
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s);
char				**ft_strsplit(const char *s, char c);
char				*ft_itoa(int n);
void				ft_putendl(const char *s);
void				ft_putnbr(int nb);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **lst, t_list *new);
void				ft_lstiter(t_list *alst, void (*f)(t_list *new));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t				ft_strlcat(char *dest, const char *src, size_t size);
void				ft_putchar_puissant(const char *str);
void				ft_foreach(int *tab, int lenght, void (*f)(int));
char				*ft_strndup(const char *s, size_t n);
void				ft_sort_integer_table(int *tab, int size);
int					skip_word(char *str, int i);
int					skip_space(char *str, int i);
int					ft_intchr(char const *str, char const *find);
int					ft_isblank(char c);
long long			ft_atol(char const *str);
long				ft_abs(long x);

#endif
