/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:19:02 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/08 13:19:15 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

int	move_cursor_next_alnum(t_matrix *matrix)
{
	matrix->cursor->col = get_cursor_pos_next_alnum(matrix);
	return (1);
}

int	move_cursor_begin_alnum(t_matrix *matrix)
{
	matrix->cursor->col = get_cursor_pos_begin_alnum(matrix);
	return (1);
}

int	move_cursor_end_alnum(t_matrix *matrix)
{
	matrix->cursor->col = get_cursor_pos_end_alnum(matrix);
	return (1);
}
