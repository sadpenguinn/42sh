/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_tree_rotate_right.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 08:58:20 by narchiba          #+#    #+#             */
/*   Updated: 2018/11/30 18:14:45 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	ft_rb_tree_rotate_right(t_rb_tree_node *x, t_rb_tree_node **root)
{
	t_rb_tree_node *y;

	y = x->left;
	if (x->parent)
	{
		if (x->parent->left == x)
			x->parent->left = y;
		else
			x->parent->right = y;
	}
	else
		*root = y;
	y->parent = x->parent;
	x->parent = y;
	x->left = y->right;
	if (y->right != NULL)
		y->right->parent = x;
	y->right = x;
}
