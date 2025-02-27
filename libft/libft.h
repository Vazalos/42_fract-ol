/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:35:54 by david-fe          #+#    #+#             */
/*   Updated: 2024/10/22 14:37:38 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// LIBFT mandatory
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
size_t			ft_strlen(const char *str);
void			*ft_memset(void *ptr, int c, size_t n);
void			ft_bzero(void *ptr, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
size_t			ft_strlcpy(char *dest, const char *src, size_t destsize);
unsigned int	ft_strlcat(const char *dst, const char *src, size_t size);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
int				ft_strncmp(char *s1, char*s2, unsigned int n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strdup(const char *src);

char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
unsigned int	ft_putchar_fd(char c, int fd);
unsigned int	ft_putstr_fd(char *str, int fd);
void			ft_putendl_fd(char *str, int fd);
unsigned int	ft_putnbr_fd(int nbr, int fd);

// LIBFT bonus
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new_node);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new_node);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst,
					void *(*f)(void *), void (*del)(void *));

// PRINTF
int				ft_printf(const char *arg_str, ...);
size_t			ft_strlen(const char *str);
char			*ft_strchr(const char *str, int c);
unsigned int	ft_putchar(char c);
unsigned int	ft_putnbr(int nbr);
unsigned int	ft_putunbr(unsigned int nbr);
unsigned int	ft_putstr(char *str);
unsigned int	ft_puthex(unsigned int to_hex, char xcase);
unsigned int	ft_putptr(void *to_ptr);
void			*ft_calloc(size_t nmemb, size_t size);

//MORE
long			ft_atol(const char *str);

#endif
