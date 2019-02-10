/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:43:52 by bwerewol          #+#    #+#             */
/*   Updated: 2018/12/09 18:44:06 by bwerewol         ###   ########.fr       */
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
