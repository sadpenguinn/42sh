/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_function_djb2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:50:29 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/14 16:57:13 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libhash.h"

/*
** Dan Bernstein hashing algorithm for variable length string
** http://www.cse.yorku.ca/~oz/hash.html
*/

t_hshindex	djb2(void *content, size_t content_size)
{
	t_hshindex	index;
	size_t		i;
	int			c;

	i = 0;
	index = 5381;
	while (i < content_size)
	{
		c = ((char *)content)[i];
		index = ((index << 5) + index) + c;
		i++;
	}
	return (index);
}
