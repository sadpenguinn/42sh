/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 20:51:15 by bwerewol          #+#    #+#             */
/*   Updated: 2018/12/16 22:55:51 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_btree_count(t_btree *root)
{
	if (!root)
		return (0);
	return (ft_btree_count(root->left) + ft_btree_count(root->right) + 1);
}
