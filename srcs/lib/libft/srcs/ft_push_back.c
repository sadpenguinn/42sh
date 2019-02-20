/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:39:12 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/20 10:41:32 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_push_back(t_list **begin, void *data)
{
	t_list *tmp;

	if (!begin)
		return (0);
	if (!(tmp = *begin))
		return (*begin = ft_listnew(data));
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->next = ft_listnew(data));
}
