/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_function_eq_djb2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:49:03 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/16 14:43:52 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libhash.h"

/*
** Dan Bernstein hashing algorithm for variable length string.
** Function adapted for strings key=value. In which lines compares to =.
** http://www.cse.yorku.ca/~oz/hash.html
*/

t_hshindex	eq_djb2(char *content)
{
	t_hshindex	index;
	size_t		i;
	int			c;

	i = 0;
	index = 5381;
	while (content[i] && content[i] != '=')
	{
		c = content[i];
		index = ((index << 5) + index) + c;
		i++;
	}
	return (index);
}
