/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_tree_rotate_left.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 08:09:14 by narchiba          #+#    #+#             */
/*   Updated: 2018/11/30 18:14:54 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	ft_rb_tree_rotate_left(t_rb_tree_node *x, t_rb_tree_node **root)
{
	t_rb_tree_node *y;

	y = x->right;
	if (x->parent != NULL)
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
	x->right = y->left;
	if (y->left != NULL)
		y->left->parent = x;
	y->left = x;
}
