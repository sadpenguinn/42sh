/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_tree_insert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:36:08 by narchiba          #+#    #+#             */
/*   Updated: 2018/12/01 16:59:32 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static t_rb_tree_node	*left_son(t_rb_tree_node *cur, t_rb_tree_node **root)
{
	if (cur->parent->parent->right &&
			cur->parent->parent->right->color == RED)
	{
		cur->parent->color = BLACK;
		cur->parent->parent->right->color = BLACK;
		cur->parent->parent->color = RED;
		cur = cur->parent->parent;
	}
	else
	{
		if (cur == cur->parent->right)
		{
			cur = cur->parent;
			ft_rb_tree_rotate_left(cur, root);
		}
		cur->parent->parent->color = RED;
		cur->parent->color = BLACK;
		ft_rb_tree_rotate_right(cur->parent->parent, root);
	}
	return (cur);
}

static t_rb_tree_node	*right_son(t_rb_tree_node *cur, t_rb_tree_node **root)
{
	if (cur->parent->parent->left &&
			cur->parent->parent->left->color == RED)
	{
		cur->parent->color = BLACK;
		cur->parent->parent->left->color = BLACK;
		cur->parent->parent->color = RED;
		cur = cur->parent->parent;
	}
	else
	{
		if (cur == cur->parent->left)
		{
			cur = cur->parent;
			ft_rb_tree_rotate_right(cur, root);
		}
		cur->parent->parent->color = RED;
		cur->parent->color = BLACK;
		ft_rb_tree_rotate_left(cur->parent->parent, root);
	}
	return (cur);
}

static void				maintain_balance(t_rb_tree_node *cur,
		t_rb_tree_node **root)
{
	while (cur != *root && cur->parent->color == RED)
	{
		if (cur->parent == cur->parent->parent->left)
			cur = left_son(cur, root);
		else
			cur = right_son(cur, root);
	}
	(*root)->color = BLACK;
}

static int				fill_in_node(t_rb_tree_node *node,
		t_rb_tree_node *parent, const void *data, size_t size)
{
	node->parent = parent;
	if (parent == NULL)
		node->color = BLACK;
	else
		node->color = RED;
	node->left = NULL;
	node->right = NULL;
	if (!(node->data = xmalloc(size)))
	{
		free(node);
		return (0);
	}
	ft_memmove(node->data, data, size);
	node->data_size = size;
	return (1);
}

t_rb_tree_node			*ft_rb_tree_insert(const void *data,
		size_t size, t_rb_tree_node **root,
		int (*cmp)(const void *, const void *))
{
	t_rb_tree_node	*cur;
	t_rb_tree_node	*parent;

	cur = *root;
	parent = NULL;
	while (cur != NULL)
	{
		parent = cur;
		if (cmp(data, cur->data) == 0)
			return (cur);
		cur = (cmp(data, cur->data) > 0) ? cur->right : cur->left;
	}
	if (!(cur = xmalloc(sizeof(t_rb_tree_node))))
		return (NULL);
	if (!(fill_in_node(cur, parent, data, size)))
		return (NULL);
	if (parent)
		if (cmp(data, parent->data) > 0)
			parent->right = cur;
		else
			parent->left = cur;
	else
		*root = cur;
	maintain_balance(cur, root);
	return (cur);
}
