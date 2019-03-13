#ifndef LIBALIAS_H
# define LIBALIAS_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

/*
** Alias functions return one if this values.
** If ret is a pointer, NULL will be returned in error case
*/

# define ALIAS_ERR 0
# define ALIAS_OK 1

/*
** Defines for alias realloc function
*/

# define ALIAS_PERCENTS_FILLED_MAX 50
# define ALIAS_PERCENTS_SIZE_REALLOC 150

/*
** Internal type for represent an index
*/

typedef unsigned long	t_aindex;

typedef struct	s_aliastb
{
	char			*key;
	char			**value;
}				t_aliastb;

typedef struct	s_alias
{
	t_aliastb	*table;
	size_t		size;
	size_t		filled;
}				t_alias;

/*
** Allocate alias table with passed size
*/

t_alias			*alias_init(size_t size);

/*
** Looks up the index of an item in a table.
** At alias or key == NULL, behavior is undefined
*/

t_aindex		alias_index(const char *key, t_alias *alias);

/*
** Function inserts cell into the table. If cells count is greater
** then ALIAS_PERCENTS_FILLED_MAX define, table size will be increased by
** ALIAS_PERCENTS_SIZE_REALLOC
*/

t_aliastb		*alias_insert(const char *key, char **value,
								t_alias *alias);

/*
** Remove one cell from the table
*/

int				alias_delete(const char *key, t_alias *alias);

/*
** Returns a pointer if there is match or NULL
*/

t_aliastb		*alias_find(const char *key, t_alias *alias);

/*
** The function just cleans the table
*/

int				alias_clean(t_alias **alias);

/*
** Prints aliases
*/

int				alias_print(t_alias *alias);

/*
** Iterates the table
*/

int				alias_foreach(t_alias *alias, void (f)(char *key, char **value));

/*
** Internal function for remove hash fields
*/

void			alias_free_fileds(char *key, char **value);

/*
** Internal function for realloc hash table
*/

int				alias_realloc(t_alias *alias, size_t new_size);

/*
** Internal function for search empty cell
*/

t_aliastb		*alias_search(const char *key, t_alias *alias, t_aindex index);

/*
** Internal tools
*/

void			alias_free_arr(char ***arr);
size_t			alias_len_arr(char **arr);
char			**alias_cpy_arr(char **arr);
char			**alias_get_arr(const char *key, t_alias *alias);

#endif
