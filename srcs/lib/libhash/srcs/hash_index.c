/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 20:22:20 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/11 19:08:09 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

static t_hshindex	eq_djb2(void *content)
{
	t_hshindex	index;
	char		*cont;
	size_t		i;
	int			c;

	i = 0;
	index = 5381;
	cont = (char *)content;
	while (cont[i] && cont[i] != '=')
	{
		c = cont[i];
		index = ((index << 5) + index) + c;
		i++;
	}
	return (index);
}

static t_hshindex	djb2(void *content, size_t content_size)
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

t_hshindex			hash_index(void *content, size_t content_size, \
														t_hshtb **table, int c)
{
	t_hshindex	index;

	if (c == HSH_DJB2)
		index = djb2(content, content_size);
	else if (c == HSH_EQ_DJB2)
		index = eq_djb2(content);
	else
		index = djb2(content, content_size);
	index = index % ((t_hshinfo *)table[0]->content)->size;
	if (!index)
		return (index + 1);
	return (index);
}
