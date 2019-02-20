/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 18:29:07 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/20 10:41:32 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_btree_del(t_btree **root, void (*f)(void *data))
{
	if (!root || !*root)
		return ;
	if ((*root)->left)
		ft_btree_del(&(*root)->left, f);
	if ((*root)->right)
		ft_btree_del(&(*root)->right, f);
	(*f)((*root)->data);
	free(*root);
	*root = 0;
}
