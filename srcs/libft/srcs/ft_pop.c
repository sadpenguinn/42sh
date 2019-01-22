/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:33:36 by bwerewol          #+#    #+#             */
/*   Updated: 2018/12/09 18:14:27 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_pop(t_list **begin)
{
	t_list *tmp;

	if (!begin || !*begin)
		return ((t_list *)0);
	tmp = *begin;
	*begin = tmp->next;
	return (tmp);
}
