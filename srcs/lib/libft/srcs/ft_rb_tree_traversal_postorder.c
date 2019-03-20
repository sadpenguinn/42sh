/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_tree_traversal_postorder.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:51:45 by narchiba          #+#    #+#             */
/*   Updated: 2018/11/30 18:33:39 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	ft_rb_tree_traversal_postorder(t_rb_tree_node *root,
		void (*f)(t_rb_tree_node *))
{
	if (!(root))
		return ;
	ft_rb_tree_traversal_postorder(root->left, f);
	ft_rb_tree_traversal_postorder(root->right, f);
	f(root);
}
