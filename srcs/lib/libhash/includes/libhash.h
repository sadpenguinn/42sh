/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libhash.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 20:18:53 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/11 19:19:27 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBHASH_H
# define LIBHASH_H

# include <stdlib.h>
# include <unistd.h>
# include "shell.h"

# define HSH_PERCENTS_FILLED_MAX 50
# define HSH_PERCENTS_SIZE_REALLOC 200

# define HSH_DEFAULT 0
# define HSH_DJB2 1
# define HSH_EQ_DJB2 2

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

t_hshindex		hash_index(void *content, size_t content_size, \
														t_hshtb **table, int c);
t_hshtb			**hash_init(size_t size, int hashing);
t_hshtb			*hash_insert(void *content, size_t content_size, \
															t_hshtb ***table);
void			hash_delete(void *content, size_t content_size, \
							t_hshtb **table, int (c)(void *el1, size_t cs1, \
														void *el2, size_t cs2));
t_hshtb			*hash_find(void *content, size_t content_size, \
	t_hshtb **table, int (c)(void *el1, size_t cs1, void *el2, size_t cs2));
void			hash_clean(t_hshtb ***tables);
void			hash_foreach(t_hshtb **table, \
								void (c)(void *content, size_t content_size));
void			hash_print(t_hshtb **table);
void			hash_test(t_hshtb **table);

#endif
