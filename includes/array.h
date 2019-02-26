/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:37:35 by narchiba          #+#    #+#             */
/*   Updated: 2019/02/26 16:41:41 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include <string.h>

enum			e_array_default_params
{
	ARRAY_DEFAULT_SIZE = 10,
	FACTOR = 2
};

typedef	struct	s_array
{
	char		*buf;
	size_t		len;
	size_t		size;
}				t_array;

void			array_add(const char *str, size_t len);
char			*array_to_string(void);
void			array_flush(void);

#endif
