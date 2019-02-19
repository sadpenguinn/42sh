/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:44:41 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/19 12:42:53 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btree_new(void *data)
{
	t_btree	*new;

	new = ft_memalloc(sizeof(t_btree));
	new->data = data;
	return (new);
}
