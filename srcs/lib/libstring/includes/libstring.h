/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstring.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:56:42 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/13 21:17:34 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSTRING_H
# define LIBSTRING_H

# include <stdlib.h>
# include "libft.h"

# define STRING_RESIZE 70
# define STRING_DEFAULT 100
# define STRING_OK 0
# define STRING_ERR 1

typedef struct	s_string
{
	char		*str;
	size_t		size;
	size_t		len;
}				t_string;

t_string		*string_init(size_t initial_size);
int 			string_resize(t_string *string);
int 			string_insert(t_string *string, char c, int pos);
int				string_join(t_string *string, char *join);
char 			*string_push(t_string *string, char *push, size_t push_size);
int 			string_free(t_string *string);

#endif
