/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:38:40 by bwerewol          #+#    #+#             */
/*   Updated: 2018/12/09 18:42:53 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_listlast(t_list *begin)
{
	if (!begin)
		return ((t_list *)0);
	while (begin->next)
		begin = begin->next;
	return (begin);
}
