/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 10:58:25 by bwerewol          #+#    #+#             */
/*   Updated: 2019/03/14 21:58:21 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

# define STYLE_DEF		0
# define STYLE_BOLD		1
# define STYLE_UNDER	4
# define STYLE_BLINK	5
# define STYLE_INV		7
# define STYLE_INVIS	8

# define COLOR_BLACK	30
# define COLOR_RED		31
# define COLOR_GREEN	32
# define COLOR_YELLOW	33
# define COLOR_BLUE		34
# define COLOR_MAGENTA	35
# define COLOR_CYAN		36
# define COLOR_WHITE	37

# define BACKG_BLACK	40
# define BACKG_RED		41
# define BACKG_GREEN	42
# define BACKG_YELLOW	43
# define BACKG_BLUE		44
# define BACKG_MAGENTA	45
# define BACKG_CYAN		46
# define BACKG_WHITE	47
# define RED 1
# define BLACK 0

/*
** Lists
*/

typedef struct				s_list
{
	void					*data;
	struct s_list			*next;
}							t_list;

t_list						*ft_listnew(void *data);
t_list						*ft_push(t_list **begin, void *data);
void						*ft_pop(t_list **begin);
t_list						*ft_push_back(t_list **begin, void *data);
t_list						*ft_listlast(t_list *begin);
void						ft_listdel(t_list **begin, void (*f)(void *data));

/*
** Binary tree
*/

typedef struct				s_btree
{
	void					*data;
	struct s_btree			*left;
	struct s_btree			*right;
}							t_btree;

typedef	struct				s_rb_tree_node
{
	struct s_rb_tree_node	*parent;
	struct s_rb_tree_node	*left;
	struct s_rb_tree_node	*right;
	int						color;
	void					*data;
	size_t					data_size;
}							t_rb_tree_node;

t_btree						*ft_btree_new(void *data);
t_btree						*ft_btree_ins(t_btree **root, void *data,
								int (*cmp)(void *, void *));
void						ft_btree_prefix(t_btree *root,
							void (*f)(void *data));
void						ft_btree_infix(t_btree *root,
							void (*f)(void *data));
void						ft_btree_suffix(t_btree *root,
							void (*f)(void *data));
t_btree						*ft_btree_search(t_btree *root, void *data,
								int (*cmp)(void *, void *));
int							ft_btree_count(t_btree *root);
void						ft_btree_del(t_btree **root, void (*f)(void *data));

int							ft_atoi_base(const char *str, const char *base);
char						*ft_itoa_base(long int num, int base);
char						*ft_strrev(char *s);
int							ft_isblank(int c);
int							ft_iscntrl(int c);
int							ft_isgraph(int c);
int							ft_islower(int c);
int							ft_isspace(int c);
int							ft_is_space_tab(int c);
int							ft_isupper(int c);
int							ft_isxdigit(int c);
int							ft_isnumber(int c);
int							ft_str_is_alpha(char *s);
int							ft_str_is_lowercase(char *s);
int							ft_str_is_numeric(char *s);
int							ft_str_is_number(char *s);
int							ft_str_is_printable(char *s);
int							ft_str_is_uppercase(char *s);
char						*ft_strupcase(char *s);
char						*ft_strlowcase(char *s);
void						*ft_memset(void *s, int c, size_t n);
void						ft_bzero(void *s, size_t n);
void						*ft_memcpy(void *dest, const void *src, size_t n);
void						*ft_memccpy(void *dest, const void *src,
											int c, size_t n);
void						*ft_memmove(void *dest, const void *src, size_t n);
void						*ft_memchr(const void *s, int c, size_t n);
int							ft_memcmp(const void *s1, const void *s2, size_t n);
size_t						ft_strlen(const char *s);
char						*ft_strdup(const char *s);
char						*ft_strndup(char *str, size_t n);
size_t						ft_strcpy(char *dest, const char *src);
char						*ft_strncpy(char *dest, const char *src, size_t n);
char						*ft_strcat(char *dest, const char *src);
char						*ft_strncat(char *dest, const char *src, size_t n);
size_t						ft_strlcat(char *dst, const char *src, size_t size);
char						*ft_strchr(const char *s, int c);
char						*ft_strrchr(const char *s, int c);
char						*ft_strstr(const char *haystack,
										const char *needle);
char						*ft_strnstr(const char *haystack,
										const char *needle,
										size_t len);
int							ft_strcmp(const char *s1, const char *s2);
int							ft_strncmp(const char *s1,
										const char *s2, size_t n);
int							ft_atoi(const char *nptr);
char						*ft_ltoa(long n);
int							ft_isalpha(int c);
int							ft_isdigit(int c);
int							ft_isalnum(int c);
int							ft_isascii(int c);
int							ft_isprint(int c);
int							ft_toupper(int c);
int							ft_tolower(int c);
void						*ft_memalloc(size_t size);
void						ft_free(void *p);
void						ft_memdel(void **ap);
char						*ft_strnew(size_t size);
void						ft_strdel(char **as);
void						ft_strclr(char *s);
void						ft_striter(char *s,
										void (*f)(char *));
void						ft_striteri(char *s,
									void (*f)(unsigned int, char *));
char						*ft_strmap(char const *s, char (*f)(char));
char						*ft_strmapi(char const *s,
								char (*f)(unsigned int, char));
int							ft_strequ(char const *s1, char const *s2);
int							ft_strnequ(char const *s1,
											char const *s2, size_t n);
char						*ft_strsub(char const *s, size_t start, size_t len);
char						*ft_strjoin(char const *s1,
										char const *s2, int free_s);
char						*ft_strtrim(char const *s);
char						**ft_strsplit(char const *s, char c);
char						*ft_itoa(int n);
void						ft_putchar(char c);
void						ft_putstr(char const *s);
void						ft_putendl(char const *s);
void						ft_putnbr(int n);
void						ft_putnbrendl(int n);
void						ft_putchar_fd(char c, int fd);
void						ft_putstr_fd(char const *s, int fd);
void						ft_putendl_fd(char const *s, int fd);
void						ft_putnbr_fd(int n, int fd);
int							ft_err_msg(char *msg, int errn);
int							ft_numlen(int64_t num, int base);
char						*ft_stradd(char *dst, char *src, int freesrc);
void						*ft_memdup(void *data, size_t size);
void						ft_putnchr(char ch, int n);
void						ft_strcolor(char *str, int x1, int x2, int x3);
int							ft_charsize(unsigned char c);
int							ft_strnum_base(char *str, long int num, int base);
int							ft_strnum(char *str, long int num);
char						*ft_pathadd(char *path, char *name);
unsigned long				ft_pow(int n, int pw);
int							fatal_error(char *message, int err);
void						*xmalloc(size_t bytes);
void						*xrealloc(void *p, size_t newsize, size_t oldsize);
void						**ft_joinvect(void **arr1, void **arr2, int free2);
t_rb_tree_node				*ft_rb_tree_find(const void *data,
									t_rb_tree_node *node,
									int (*cmp)(const void *data1,
									const void *data2));
void						ft_rb_tree_delete(t_rb_tree_node *node,
									t_rb_tree_node **root);
t_rb_tree_node				*ft_rb_tree_minimum(t_rb_tree_node *node);
t_rb_tree_node				*ft_rb_tree_maximum(t_rb_tree_node *node);
void						ft_rb_tree_traversal_postorder(t_rb_tree_node *root,
									void (*f)(t_rb_tree_node *node));
void						ft_rb_tree_traversal_inorder(t_rb_tree_node *root,
									void (*f)(t_rb_tree_node *node));
void						ft_rb_tree_traversal_preorder(t_rb_tree_node *root,
									void (*f)(t_rb_tree_node *ndoe));
t_rb_tree_node				*ft_rb_tree_insert(const void *data,
									size_t size, t_rb_tree_node **root,
									int (*cmp)(const void *data1,
												const void *data2));
void						ft_rb_tree_rotate_right(t_rb_tree_node *x,
											t_rb_tree_node **root);
void						ft_rb_tree_rotate_left(t_rb_tree_node *x,
										t_rb_tree_node **root);
int							ft_strchrc(char *str, char c);

#endif
