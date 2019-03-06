/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_tree_maximum.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 07:04:58 by narchiba          #+#    #+#             */
/*   Updated: 2018/12/01 12:05:56 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

t_rb_tree_node	*ft_rb_tree_maximum(t_rb_tree_node *node)
{
	if (node == NULL)
		return (NULL);
	while (node->right)
		node = node->right;
	return (node);
}
