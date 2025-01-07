/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macorso <maxence22corso@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:23:39 by macorso           #+#    #+#             */
/*   Updated: 2025/01/07 22:14:29 by macorso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
size_t	ft_strlen(const char *str);
int		ft_isprint(int c);
void	*ft_memset(void *s, int v, size_t c);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *d, const void *s, size_t n);
void	*ft_memmove(void *d, const void *s, size_t n);
size_t	ft_strlcpy(char *d, const char *s, size_t n);
size_t	ft_strlcat(char *d, const char *s, size_t n);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *str, int searched);
char	*ft_strrchr(const char *str, int searched);
int		ft_strncmp(const char *f, const char *s, size_t n);
void	*ft_memchr(const void *memBlock, int c, size_t n);
int		ft_memcmp(const void *p1, const void *p2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t n);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t element_count, size_t element_size);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

int		ft_endl(char *str);

char	*extract_line(char *buffer);
char	*trim_buffer(char *buffer);
char	*read_and_append(int fd, char *buffer);
char	*get_next_line(int fd);

int		ft_print_unsigned(unsigned int num);
int		ft_print_ptr(unsigned long long ptr);
int		ft_print_hex(unsigned int num, const char format);
int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_printnbr(int nb);
int		ft_printpercent(void);

#endif
