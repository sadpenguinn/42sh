/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 13:01:56 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/16 14:42:15 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libhash.h"
#include "libft.h"

static void	print_row(t_hshtb *row)
{
	int		flag;

	flag = 0;
	while (row)
	{
		flag = 1;
		write(1, row->content, ft_strlen(row->content));
		write(1, " -> ", 4);
		row = row->next;
	}
	if (flag)
		write(1, "\n", 1);
}

/*
** Just printing the table
*/

void		hash_print(t_hshtb **table)
{
	t_hshtb		*tmp;
	size_t		size;
	size_t		i;

	if (!table)
		return ;
	i = 1;
	size = ((t_hshinfo *)table[0]->content)->size;
	while (i < size)
	{
		if ((tmp = table[i]))
		{
			write(1, C_GREEN"Row ", 4 + 5);
			ft_putnbrendl((int)i);
			write(1, C_DEFAULT, 5);
			print_row(tmp);
		}
		i++;
	}
	write(1, C_GREEN"Size: ", 6 + 5);
	ft_putnbrendl((int)(((t_hshinfo *)table[0]->content)->size));
	write(1, "Filled: ", 8);
	ft_putnbrendl((int)(((t_hshinfo *)table[0]->content)->filled));
	write(1, C_DEFAULT, 5);
}
