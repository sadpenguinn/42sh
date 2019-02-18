/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:33:36 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/18 18:49:40 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_pop(t_list **begin)
{
	t_list	*tmp;
	void	*data;

	if (!begin || !*begin)
		return ((t_list *)0);
	tmp = *begin;
	*begin = tmp->next;
	data = tmp->data;
	free(tmp);
	return (data);
}
