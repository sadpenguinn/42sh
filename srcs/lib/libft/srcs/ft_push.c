/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:43:52 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/20 10:41:32 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_push(t_list **begin, void *data)
{
	t_list *new;

	if (!(new = ft_listnew(data)))
		return ((t_list *)0);
	new->next = *begin;
	return (*begin = new);
}
