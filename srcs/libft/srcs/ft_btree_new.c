/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:44:41 by bwerewol          #+#    #+#             */
/*   Updated: 2018/12/09 18:27:02 by bwerewol         ###   ########.fr       */
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
