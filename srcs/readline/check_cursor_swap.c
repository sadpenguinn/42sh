/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cursor_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 13:11:51 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/09 13:11:57 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void	check_swap(t_cursor *start, t_cursor *end)
{
	t_cursor	tmp;

	if (start->row > end->row ||
		(start->row == end->row && start->col > end->col))
	{
		tmp.row = start->row;
		tmp.col = start->col;
		start->row = end->row;
		start->col = end->col;
		end->row = tmp.row;
		end->col = tmp.col;
	}
}
