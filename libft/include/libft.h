/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 14:46:35 by zsyyida           #+#    #+#             */
/*   Updated: 2022/12/19 13:50:27 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include	<stdio.h>
# include	<stdarg.h>

typedef struct s_list
{
	void				*content;
	int					index;
	struct s_list		*next;
	struct s_list		*prev;
}	t_list;

int		ft_isdigit(int c);
void	*ft_memchr(const void *s, int c, size_t n);
size_t	ft_strlen_ft(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy_ft(void *dst, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr_ft(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *h, const char *n, size_t len);
char	*ft_strdup_ft(const char *s1);
void	*ft_calloc(size_t count, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_itoa(int n);
char	*ft_strjoin_ft(char *s1, char *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char *s, char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstadd_back(t_list **lst, t_list *new);
void	*ft_lstdelone(t_list *lst, void (*del)(t_list*));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void*));
t_list	*ft_lstnew_ps(void *content, int index);
t_list	*ft_lstmap(t_list *lst, long long (*f)(t_list *), void (*del)(void *));
void	del(void *s);

int		ft_printf(const char *format, ...);
void	ft_parse_format(char c, va_list ap, int *len);
void	ft_print_char(char c, int *len);
void	ft_putstr(char *s, int *len);
void	ft_print_ptr(unsigned long long n, int *len);
void	ft_print_ptrhex(unsigned long long n, int *len);
void	ft_putnbr(int n, int *len);
void	ft_print_u(unsigned int n, int *len);
void	ft_print_hex(unsigned int n, int *len, char c);
void	ft_parse_bonus(char c, va_list ap, char d, int *len);
void	ft_print_0x(va_list ap, int c, int *len);
void	ft_print_positive(va_list ap, int c, int d, int *len);
void	ft_print_list_char(t_list *lst);
void	ft_print_list_int(t_list *lst);

void	ft_free_s(char *str);
void	ft_free_p(void *ptr);

char	*get_next_line(int fd);
int		ft_line_len(char *s, int c);
char	*ft_strdup_update(char *s1);
int		ft_strlen(char *s);
char	*ft_strnjoin(char *s1, char *s2, int n);
char	*ft_strndup(char *input, int n);
void	ft_free(char **p);
void	*ft_memcpy(char *dst, char *src, int n);
char	*ft_output(char **next_line);
char	*ft_nl_output(char	**next_line);
int		ft_strchr_gnl(char *next_line, int c);

#endif
