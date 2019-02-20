/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_search.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 19:44:00 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/20 10:41:32 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btree_search(t_btree *root, void *data,
						int (*cmp)(void *, void *))
{
	int	res;

	if (!root)
		return ((t_btree *)0);
	if (!(res = (*cmp)(root->data, data)))
		return (root);
	if (res < 0)
		return (ft_btree_search(root->left, data, cmp));
	else
		return (ft_btree_search(root->right, data, cmp));
}
