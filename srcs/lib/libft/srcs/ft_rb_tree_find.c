/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_tree_find.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:23:22 by narchiba          #+#    #+#             */
/*   Updated: 2018/12/01 16:05:40 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

t_rb_tree_node	*ft_rb_tree_find(const void *data,
		t_rb_tree_node *node, int (*cmp)(const void *data1, const void *data2))
{
	while (node != NULL)
	{
		if (cmp(data, node->data) == 0)
			return (node);
		node = (cmp(data, node->data) > 0) ? node->right : node->left;
	}
	return (NULL);
}
