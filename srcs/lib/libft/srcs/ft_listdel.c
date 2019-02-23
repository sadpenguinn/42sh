/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 15:58:14 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/21 10:55:31 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_listdel(t_list **begin, void (*f)(void *data))
{
	t_list	*lst;
	t_list	*tmp;

	lst = *begin;
	*begin = 0;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		(*f)(tmp->data);
		free(tmp);
	}
}
