/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_function_djb2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:50:29 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/16 14:43:01 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libhash.h"

/*
** Dan Bernstein hashing algorithm for variable length string
** http://www.cse.yorku.ca/~oz/hash.html
*/

t_hshindex	djb2(char *content)
{
	t_hshindex	index;
	size_t		i;
	int			c;

	i = 0;
	index = 5381;
	while (content[i])
	{
		c = content[i];
		index = ((index << 5) + index) + c;
		i++;
	}
	return (index);
}
