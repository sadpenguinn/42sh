/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_tree_traversal_inorder.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:50:09 by narchiba          #+#    #+#             */
/*   Updated: 2018/11/30 18:27:54 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	ft_rb_tree_traversal_inorder(t_rb_tree_node *root,
		void (*f)(t_rb_tree_node *node))
{
	if (root == NULL)
		return ;
	ft_rb_tree_traversal_inorder(root->left, f);
	f(root);
	ft_rb_tree_traversal_inorder(root->right, f);
}
