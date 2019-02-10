/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_infix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 19:28:46 by bwerewol          #+#    #+#             */
/*   Updated: 2018/12/09 19:37:29 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_infix(t_btree *root, void (*f)(void *data))
{
	if (!root)
		return ;
	if (root->left)
		ft_btree_infix(root->left, f);
	(*f)(root->data);
	if (root->right)
		ft_btree_infix(root->right, f);
}
