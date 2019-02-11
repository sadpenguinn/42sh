/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 13:18:05 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/11 19:09:04 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"
#include "libft.h"

void	hash_test(t_hshtb **table)
{
	t_hshtb	*tmp;
	size_t	i;
	int		cnt;

	i = 1;
	cnt = 0;
	while (i < ((t_hshinfo *)table[0]->content)->size)
	{
		tmp = table[i];
		while (tmp)
		{
			if (tmp->next)
				cnt++;
			tmp = tmp->next;
		}
		i++;
	}
	write(1, "Collision test: ", 16);
	ft_putnbr(cnt);
	write(1, "\n", 1);
}
