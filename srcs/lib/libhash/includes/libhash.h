/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libhash.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 20:18:53 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/20 12:15:07 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBHASH_H
# define LIBHASH_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

/*
** Hash functions return one if this values.
** If ret is a pointer, NULL will be returned in error case
*/
# define HSH_ERR 0
# define HSH_OK 1

/*
** Defines for hash realloc function
*/
# define HSH_PERCENTS_FILLED_MAX 50
# define HSH_PERCENTS_SIZE_REALLOC 150

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

/*
** Internal type for represent an index
*/
typedef unsigned long	t_hshindex;

typedef struct	s_hshtb
{
	char			*key;
	char 			*value;
	void			*data;
	struct s_hshtb	*next;
}				t_hshtb;

typedef struct	s_hash
{
	t_hshtb		*table;
	size_t		size;
	size_t		filled;
}				t_hash;

/*
** Allocate hash table with passed size
*/

t_hash			*hash_init(size_t size);

/*
** Looks up the index of an item in a table.
** At hash or key == NULL, behavior is undefined
*/

t_hshindex		hash_index(const char *key, t_hash *hash);

/*
** Function insert cell into the table. If cells count is greater
** then HSH_PERCENTS_FILLED_MAX define, table size will be increased by
** HSH_PERCENTS_SIZE_REALLOC
*/

t_hshtb			*hash_insert(const char *key, const char *value, t_hash *hash, void *data);

/*
** Remove one cell from the table
*/

int 			hash_delete(const char *key, t_hash *hash);

/*
** Returns a pointer if there is match or NULL
*/

t_hshtb			*hash_find(const char *key, t_hash *hash);

/*
** The function just cleans the table
*/

int 			hash_clean(t_hash **hash);

/*
** Iterates the table
*/

int 			hash_foreach(t_hash *hash, void (f)(char *key, char *value));

/*
** Returns size of table
*/

size_t			hash_get_size(t_hash *hash);

/*
** Returns length of table
*/

size_t			hash_get_len(t_hash *hash);

/*
** Just printing the table
*/

int 			hash_print(t_hash *hash);

/*
** Counts the number of collision
*/

int 			hash_test(t_hash *hash);

/*
** Internal function for remove hash fields
*/

void			hash_free_fileds(char *key, char *value);

#endif
