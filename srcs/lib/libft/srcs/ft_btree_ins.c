/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_ins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:51:17 by bwerewol          #+#    #+#             */
/*   Updated: 2018/12/26 17:24:44 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btree_ins(t_btree **root, void *data, int (*cmp)(void*, void*))
{
	t_btree	**tmp;

	tmp = root;
	while (*tmp)
	{
		if (cmp(data, (*tmp)->data) < 0)
			tmp = &((*tmp)->left);
		else
			tmp = &((*tmp)->right);
	}
	return (*tmp = ft_btree_new(data));
}
