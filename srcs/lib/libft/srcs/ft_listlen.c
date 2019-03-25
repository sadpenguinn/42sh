/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:38:40 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/27 12:51:35 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_listlen(t_list *begin)
{
	size_t	len;

	if (!begin)
		return (0);
	len = 0;
	while (begin)
	{
		++len;
		begin = begin->next;
	}
	return (len);
}
