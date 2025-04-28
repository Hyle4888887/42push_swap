/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:05:57 by mpoirier          #+#    #+#             */
/*   Updated: 2025/04/28 11:47:49 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <limits.h>
# include <string.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <stdint.h>

// Fonctions len_of
int			ft_strlen(const char *str);
int			ft_nbrlen(long long nb, int bn);
int			ft_nbulen(size_t nb, int bn);
int			ft_ptrlen(unsigned long addr);

// Fonctions nbr_to_str et inverse
int			ft_atoi(const char *nptr);
char		*ft_itoa(int nb);
char		*ft_sttoa(size_t nb);
char		*ft_lltoa(long long nb);
char		*ft_dtoa(double n, int decimals);
char		*ft_sttohex(size_t nb, bool up);
size_t		ft_atost(const char *str);
double		ft_atod(const char *str);
long long	ft_atoll(const char *str);
// les nbr_to_str sont à free

// Fonctions memoires
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);

// Fonctions put_fd
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(const char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(const char *s, int fd);

// Fonctions duplicate_str
int			ft_strncmp(const char *s1, const char *s2, unsigned int n);
char		*ft_strdup(const char *s);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);

// Fonctions manipulate_str
// #1
char		*ft_strrchr(const char *s, int c);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
// #3
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strnstr(const char *big, const char *little, size_t len);

// Fonctions change_alpha_str
int			ft_tolower(int c);
int			ft_toupper(int c);
char		*ft_str_to(const char *str, int (*f)(int));
char		*ft_str_inversealpha(const char *str);

// Fonctions str_is
bool		ft_isalnum(int c);
bool		ft_isalpha(int c);
bool		ft_isascii(int c);
bool		ft_isdigit(int c);
bool		ft_isprint(int c);
bool		ft_isupperalpha(int c);
bool		ft_isloweralpha(int c);
bool		ft_str_is(const char *str, bool (*f)(int));

// FT_SPLIT
void		ft_free_split(char **tab);
char		**ft_split(char const *s, char c);

// Fonctions d'allocations
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_realloc(void *ptr, size_t new_size);

/*
// Fonctions manipulations de listes
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;

int			ft_lstsize(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(void *content);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
*/

#endif
