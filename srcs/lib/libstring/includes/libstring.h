/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstring.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:56:42 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/19 22:08:18 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSTRING_H
# define LIBSTRING_H

# include <stdlib.h>
# include "libft.h"

/*
** How many percent of the line size increases
** when the boundary is reached
*/
# define STRING_RESIZE 70

/*
** If initial size not passed to string_init
** function, this define will be used
*/
# define STRING_DEFAULT 100
# define STRING_OK 0
# define STRING_ERR 1

typedef struct	s_string
{
	char		*str;
	size_t		size;
	size_t		len;
}				t_string;

/*
** Init string with initial size or STRING_DEFAULT define
*/

t_string		*string_init(size_t initial_size);

/*
** Internal function for realloc string
*/

int				string_resize(t_string *string);

/*
** Inserts char to passed position, if position greater
** then size of string, string will be reallocated
*/

int				string_insert(t_string *string, char c, size_t pos);

/*
** Just concatenates strings
*/

int				string_join(t_string *string, char *join);

/*
** Concatenates strings without processing \0. If "hello\0"
** and "hello\0" were passed, the result will be "hello\0hello\0".
** If push_size is 0, the entire string will be attached
*/

char			*string_push(t_string *string, char *push, size_t push_size);

/*
** Clear memory, allocated for struct and string,
** NULL protected
*/

int				string_free(t_string *string);

#endif
