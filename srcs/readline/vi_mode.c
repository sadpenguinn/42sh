/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_mode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:27:28 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/08 13:27:29 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

int	vi_mode(t_uchar c)
{
	t_matrix	*matrix;

	matrix = g_history->matrix[g_history->cur];
	if (g_vi_mode == INSERT_MODE)
		return (vi_mode_insert(matrix, c));
	if (g_vi_mode == NORMAL_MODE)
		return (vi_mode_normal(matrix, c));
	if (g_vi_mode == REPLACE_MODE)
		return (vi_mode_replace(matrix, c));
	if (g_vi_mode == VISUAL_MODE)
		return (vi_mode_visual(matrix, c));
	return (1);
}
