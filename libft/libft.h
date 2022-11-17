/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:15:41 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/17 10:30:49 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// Return 1 if c is alphabethic caractere
int		ft_isalpha(int c);

// Return 1 if c is a numeric caractere
int		ft_isdigit(int c);

// Return 1 if c is a alphabethic or numeric caractere
int		ft_isalnum(int c);

// Return 1 if c is an ascii caractere
int		ft_isascii(int c);

// Return 1 if c is a printable caractere
int		ft_isprint(int c);

// Return size of string passed
size_t	ft_strlen(const char *s);

// Set the n first bytes at c in the memorie pointed by s
void	*ft_memset(void *s, int c, size_t n);

// Same as memset with 0
// Return nothing
void	ft_bzero(void *s, size_t n);

// Copy n first bytes of src memorie to dest memorie
void	*ft_memcpy(void *dest, const void *src, size_t n);

// Copy n first bytes of src to dest with a temporarie stocking
void	*ft_memmove(void *dest, const void *src, size_t n);

// Copy n - 1 first caracteres from src to dest
size_t	ft_strlcpy(char *dest, const char *src, size_t n);

// Concatenate src at end of dest
size_t	ft_strlcat(char *dest, const char *src, size_t n);

// Return upper caractere of c if is a lowercase caractere
int		ft_toupper(int c);

// Return lower caractere of c if is a uppercase caractere
int		ft_tolower(int c);

// Return first occurence of c in the string s, 0 if not found
char	*ft_strchr(const char *s, int c);

// Return last occurence of c in the string s, 0 if not found
char	*ft_strrchr(const char *s, int c);

// Return negative number if first is less than sec, positive if sec is greater
// than first, and 0 if they are same
int		ft_strncmp(const char *first, const char *sec, size_t n);

// Return first occurence of c in src
void	*ft_memchr(const void *src, int c, size_t n);

// Return difference (s - c) when differents
int		ft_memcmp(const void *s, const void *c, size_t n);

// Return first occurence of little
char	*ft_strnstr(const char *big, const char *little, size_t n);

// Change int string to int
int		ft_atoi(const char *s);

// Same as malloc but fill with 0
void	*ft_calloc(size_t nbr, size_t size);

// Duplicate string in another string allocated
char	*ft_strdup(const char *src);

// Copy len caracteres from s[start]
// Return this new string or 0 if didn't work
char	*ft_substr(const char *s, unsigned int start, size_t len);

// Return new string what is src concatenated to dest
char	*ft_strjoin(const char *dest, const char *src);

// Return a new string src without caracteres in set
char	*ft_strtrim(const char *src, const char *set);

// Return a new string src without caracteres in set
char	**ft_split(const char *src, char set);

// Inverse of atoi
char	*ft_itoa(int n);

// Duplicate str and affect f on each caracteres of new string
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));

// Affect the fontion f for each caracteres
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

// Write caractere c in descriptor file fd
void	ft_putchar_fd(char c, int fd);

// Write string s in descriptor file fd
void	ft_putstr_fd(char *s, int fd);

// Write string s in descriptor file fd with end line
void	ft_putendl_fd(char *s, int fd);

// Write integer n in descriptor file fd with end line
void	ft_putnbr_fd(int n, int fd);

//################### BONUS #####################
// Creat a new cell with next = 0 and content = new_content
t_list	*ft_lstnew(void *new_content);

// Add new in front of list pointed by lst
void	ft_lstadd_front(t_list **lst, t_list *new);

// Return lenght of lst
int		ft_lstsize(t_list *lst);

// Return last cell of list
t_list	*ft_lstlast(t_list *lst);

// Add new at the end of list
void	ft_lstadd_back(t_list **lst, t_list *new);

// Remove one element of list
void	ft_lstdelone(t_list *lst, void (*del)(void *));

// Clear all the list
void	ft_lstclear(t_list **lst, void (*del)(void *));

// Apply f function to all contents of list
void	ft_lstiter(t_list *lst, void (*f)(void *));

// Apply f function to all contents and creat a new list with modifications
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
#endif
