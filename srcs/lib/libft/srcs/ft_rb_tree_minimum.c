/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_tree_minimum.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 07:01:20 by narchiba          #+#    #+#             */
/*   Updated: 2018/12/01 12:05:17 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

t_rb_tree_node	*ft_rb_tree_minimum(t_rb_tree_node *node)
{
	if (node == NULL)
		return (NULL);
	while (node->left)
		node = node->left;
	return (node);
}
