/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 21:10:02 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/20 10:41:32 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_sort_ins(t_btree **root, t_btree *node,
							int (*cmp)(void *, void*))
{
	if (!root)
		return ;
	if (!*root)
		*root = node;
	if (cmp(node->data, (*root)->data) < 0)
		ft_sort_ins(&((*root)->left), node, cmp);
	else
		ft_sort_ins(&((*root)->right), node, cmp);
}

static void	ft_apply_sort(t_btree *root, t_btree **new_root,
							int (*cmp)(void *, void*))
{
	if (!root || !new_root)
		return ;
	if (root->left)
		ft_apply_sort(root->left, new_root, cmp);
	ft_sort_ins(new_root, root, cmp);
	if (root->right)
		ft_apply_sort(root->right, new_root, cmp);
}

t_btree		*ft_btree_sort(t_btree **root, int (*cmp)(void *, void *))
{
	t_btree	*new_root;

	ft_apply_sort(*root, &new_root, cmp);
	return (*root = new_root);
}
