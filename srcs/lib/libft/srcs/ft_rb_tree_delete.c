/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_tree_delete.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:08:16 by narchiba          #+#    #+#             */
/*   Updated: 2018/12/01 14:37:22 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static int				are_black_nephews(t_rb_tree_node *cur)
{
	if ((cur->left == NULL || cur->left->color == BLACK) &&
			(cur->right == NULL || cur->right->color == BLACK))
	{
		cur->color = RED;
		return (1);
	}
	return (0);
}

static t_rb_tree_node	*left_son(t_rb_tree_node *cur, t_rb_tree_node **root)
{
	if (cur->parent->right->color == RED)
	{
		cur->parent->right->color = BLACK;
		cur->parent->color = RED;
		ft_rb_tree_rotate_left(cur->parent, root);
	}
	if (are_black_nephews(cur->parent->right))
		cur = cur->parent;
	else
	{
		if (cur->parent->right->right == NULL ||
				cur->parent->right->right->color == BLACK)
		{
			cur->parent->right->left->color = BLACK;
			cur->parent->right->color = RED;
			ft_rb_tree_rotate_right(cur->parent->right, root);
		}
		cur->parent->right->color = cur->parent->color;
		cur->parent->color = BLACK;
		if (cur->parent->right->right)
			cur->parent->right->right->color = BLACK;
		ft_rb_tree_rotate_left(cur->parent, root);
		cur = *root;
	}
	return (cur);
}

static t_rb_tree_node	*right_son(t_rb_tree_node *cur, t_rb_tree_node **root)
{
	if (cur->parent->left->color == RED)
	{
		cur->parent->left->color = BLACK;
		cur->parent->color = RED;
		ft_rb_tree_rotate_right(cur->parent, root);
	}
	if (are_black_nephews(cur->parent->left))
		cur = cur->parent;
	else
	{
		if (cur->parent->left->left == NULL ||
				cur->parent->left->left->color == BLACK)
		{
			cur->parent->left->right->color = BLACK;
			cur->parent->left->color = RED;
			ft_rb_tree_rotate_left(cur->parent->left, root);
		}
		cur->parent->left->color = cur->parent->color;
		cur->parent->color = BLACK;
		if (cur->parent->left->left)
			cur->parent->left->left->color = BLACK;
		ft_rb_tree_rotate_right(cur->parent, root);
		cur = *root;
	}
	return (cur);
}

static void				maintain_balance(t_rb_tree_node *cur,
		t_rb_tree_node **root)
{
	t_rb_tree_node *tmp;

	tmp = cur;
	if (cur->color == BLACK)
	{
		while (cur != *root && cur->color == BLACK)
		{
			if (cur == cur->parent->left)
				cur = left_son(cur, root);
			else
				cur = right_son(cur, root);
		}
		cur->color = BLACK;
	}
	if (tmp->parent)
	{
		if (tmp->parent->right == tmp)
			tmp->parent->right = NULL;
		else
			tmp->parent->left = NULL;
	}
}

void					ft_rb_tree_delete(t_rb_tree_node *node,
		t_rb_tree_node **root)
{
	t_rb_tree_node	*cur;
	void			*tmp_data;

	if (node == NULL)
		return ;
	if (!(cur = ft_rb_tree_maximum(node->left)))
		cur = ft_rb_tree_minimum(node->right);
	if (cur != NULL)
	{
		tmp_data = cur->data;
		cur->data = node->data;
		node->data = tmp_data;
	}
	else
		cur = node;
	maintain_balance(cur, root);
	free(cur->data);
	free(cur);
	if (cur == *root)
		*root = NULL;
}
