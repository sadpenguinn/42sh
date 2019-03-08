/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:07:13 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/08 13:07:30 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

int	move_history_prev(void)
{
	if (g_history->cur)
	{
		matrix_to_string(g_history->matrix[g_history->cur],
				g_history->matrix[g_history->cur]->str_history);
		g_history->cur--;
		move_cursor_end(g_history->matrix[g_history->cur]);
	}
	return (1);
}

int	move_history_next(void)
{
	if (g_history->cur != g_history->len - 1)
	{
		matrix_to_string(g_history->matrix[g_history->cur],
				g_history->matrix[g_history->cur]->str_history);
		g_history->cur++;
		move_cursor_end(g_history->matrix[g_history->cur]);
	}
	return (1);
}
