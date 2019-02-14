/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libhash.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 20:18:53 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/14 17:30:09 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBHASH_H
# define LIBHASH_H

# include <stdlib.h>
# include <unistd.h>

/*
** Defines for hash realloc function
*/
# define HSH_PERCENTS_FILLED_MAX 50
# define HSH_PERCENTS_SIZE_REALLOC 200

/*
** Defines for nomination hashing algorithms
*/
# define HSH_DEFAULT 0
# define HSH_DJB2 1
# define HSH_EQ_DJB2 2

# ifndef C_COLORS
#  define C_COLORS
#  define C_DEFAULT "\x1b[0m"
#  define C_BOLD "\x1b[1m"
#  define C_LIGHT "\x1b[2m"
#  define C_RM_LIGHT "\x1b[22m"
#  define C_UNDERLINE "\x1b[4m"
#  define C_RM_UNDERLINE "\x1b[24m"
#  define C_BLINK "\x1b[5m"
#  define C_RM_BLINK "\x1b[25m"

#  define C_BLACK "\x1b[30m"
#  define C_RED "\x1b[31m"
#  define C_GREEN "\x1b[32m"
#  define C_YELLOW "\x1b[33m"
#  define C_BLUE "\x1b[34m"
#  define C_PURPLE "\x1b[35m"
#  define C_AQUA "\x1b[36m"
#  define C_GRAY "\x1b[37m"

#  define BG_BLACK "\x1b[40m"
#  define BG_RED "\x1b[41m"
#  define BG_GREEN "\x1b[42m"
#  define BG_YELLOW "\x1b[43m"
#  define BG_BLUE "\x1b[44m"
#  define BG_PURPLE "\x1b[45m"
#  define BG_AQUA "\x1b[46m"
#  define BG_GRAY "\x1b[47m"
# endif

typedef unsigned long	t_hshindex;

typedef struct	s_hshtb
{
	void			*content;
	size_t			content_size;
	struct s_hshtb	*next;
}				t_hshtb;

typedef struct	s_hshinfo
{
	size_t		size;
	size_t		filled;
	int			hashing;
}				t_hshinfo;

/*
** Looks up the index of an item in a table. 'c' argument
** is hashing algorithm define. If c does't correspond
** to more than one define djb2 will be selected
*/

t_hshindex		hash_index(void *content, size_t content_size, \
														t_hshtb **table, int c);

/*
** Allocate hash table with passed size and hash function.
** Hashing algorithm transmitted as define
*/

t_hshtb			**hash_init(size_t size, int hashing);

/*
** Function insert cell into the table. If the row already has a cell,
** new node joins the end of the list. If cell count is greater
** then HSH_PERCENTS_FILLED_MAX define, table size increase by
** HSH_PERCENTS_SIZE_REALLOC
*/

t_hshtb			*hash_insert(void *content, size_t content_size, \
															t_hshtb ***table);

/*
** Remove one cell in the table
*/

void			hash_delete(void *content, size_t content_size, \
							t_hshtb **table, int (c)(void *el1, size_t cs1, \
														void *el2, size_t cs2));

/*
** Returns a pointer if there is match, else NULL will be returned
*/

t_hshtb			*hash_find(void *content, size_t content_size, \
	t_hshtb **table, int (c)(void *el1, size_t cs1, void *el2, size_t cs2));

/*
** Function just clears the table
*/

void			hash_clean(t_hshtb ***tables);

/*
** Iterates the table
*/

void			hash_foreach(t_hshtb **table, \
								void (c)(void *content, size_t content_size));

/*
** Just printing the table
*/

void			hash_print(t_hshtb **table);

/*
** Counts the number of collision
*/

void			hash_test(t_hshtb **table);

/*
** Hash functions
*/

/*
** Dan Bernstein hashing algorithm for variable length string
** http://www.cse.yorku.ca/~oz/hash.html
*/

t_hshindex		djb2(void *content, size_t content_size);

/*
** Dan Bernstein hashing algorithm for variable length string.
** Function adapted for strings key=value. In which lines compares to =.
** http://www.cse.yorku.ca/~oz/hash.html
*/

t_hshindex		eq_djb2(void *content);

#endif
