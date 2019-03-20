/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_tree_traversal_preorder.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:50:52 by narchiba          #+#    #+#             */
/*   Updated: 2018/11/30 18:27:49 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	ft_rb_tree_traversal_preorder(t_rb_tree_node *root,
		void (*f)(t_rb_tree_node *))
{
	if (!(root))
		return ;
	f(root);
	ft_rb_tree_traversal_preorder(root->left, f);
	ft_rb_tree_traversal_preorder(root->right, f);
}
