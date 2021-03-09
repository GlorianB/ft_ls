/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <gbikoumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 22:10:06 by gbikoumo          #+#    #+#             */
/*   Updated: 2019/11/23 09:38:36 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, void const *src, size_t n);
void			*ft_memccpy(void *dst, void const *src, int c, size_t n);
void			*ft_memmove(void *dst, void const *src, size_t len);
void			*ft_memchr(void const *s, int c, size_t n);
int				ft_memcmp(void const *s1, void const *s2, size_t n);
size_t			ft_strlen(char const *s);
char			*ft_strdup(char const *s1);
char			*ft_strcpy(char *dst, char const *src);
char			*ft_strncpy(char *dst, char const *src, size_t len);
char			*ft_strcat(char *s1, char const *s2);
char			*ft_strncat(char *s1, char const *s2, size_t n);
size_t			ft_strlcat(char *dst, char const *src, size_t size);
char			*ft_strchr(char const *s, int c);
char			*ft_strrchr(char const *s, int c);
char			*ft_strstr(char const *haystack, char const *needle);
char			*ft_strnstr(char const *haystack, char const *needle,
		size_t len);
int				ft_strcmp(char const *s1, char const *s2);
int				ft_strncmp(char const *s1, char const *s2, size_t n);
int				ft_atoi(char const *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int				ft_isesc(int c);
int				ft_isupper(int c);
int				ft_islower(int c);
char			*ft_strndup(char const *s1, size_t len);
void			ft_print_words_table(char **tab);
size_t			ft_count_letter(char const *s);
size_t			ft_count_str(char const *s);
size_t			ft_count_str_sep(char const *s, char separator);
int				ft_size_nb(int n);
int				ft_count(int n);
size_t			ft_strclen(char const *s, char c);
char			*ft_strcdup(char const *s1, char c);
void			*ft_realloc(void *ptr, size_t size);
int				ft_strcchri(char const *s, int c);
void			ft_strclean(char **s, char const *tmp);
void			ft_strrev(char *str);
char			*ft_straddc(char *str, char c);
char			ft_convert_base(int nb);
char			*ft_itoa_base(int nb, int base);
char			*ft_illtoa_base(long long nb, int base);
char			*ft_iltoa_base(long n, int base);
char			*ft_illtoa(long long n);
char			*ft_iltoa(long n);
char			*ft_utoa_base(unsigned nb, int base);
char			*ft_ulltoa_base(unsigned long long nb, int base);
char			*ft_ultoa_base(unsigned long n, int base);
char			*ft_ulltoa(unsigned long long n);
char			*ft_ultoa(unsigned long n);
void			ft_str_minimize(char **str);
char			*ft_insertc(char**str, char c, int pos);
long long		ft_power(int base, int pow);
char			*ft_strjoin_free(char const *s1, char const *s2, int opt);
char			*ft_llftoa_base(long double nb, int base, int accur);
char			*ft_lftoa(double nb, int accur);
char			*ft_ftoa(float nb, int accur);
char			*ft_roundc(char *floattant, int accur);
int				ft_count_char_elem(char **tab);
char			**ft_tabdup_char(char **tab);
int				*ft_intdup(int *tab, int n);

#endif
