/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <sitlcead@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:11:56 by sitlcead          #+#    #+#             */
/*   Updated: 2019/03/03 18:17:39 by sitlcead         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

int	move_cursor_home(t_matrix *matrix)
{
	matrix->cursor->col = get_cursor_pos_home(matrix);
	return (1);
}

int	move_cursor_end(t_matrix *matrix)
{
	matrix->cursor->col = get_cursor_pos_end(matrix);
	return (1);
}
