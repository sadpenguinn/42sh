/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:57:47 by bwerewol          #+#    #+#             */
/*   Updated: 2018/12/09 18:32:27 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_listnew(void *data)
{
	t_list *new;

	if (!(new = ft_memalloc(sizeof(t_list))))
		return ((t_list *)0);
	new->data = data;
	return (new);
}
