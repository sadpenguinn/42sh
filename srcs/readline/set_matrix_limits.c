/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_matrix_limits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:07:24 by narchiba          #+#    #+#             */
/*   Updated: 2019/02/26 17:10:14 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

static int	change_limits_left_case(t_matrix *matrix, size_t new_left_limit)
{
	size_t	size;
	size_t	i;

	matrix->left_limit = new_left_limit;
	matrix->right_limit = new_left_limit;
	size = g_w.ws_col * g_w.ws_row;
	i = ((matrix->lines[matrix->right_limit]->symbols +
				get_lines_prompt_len(matrix->len) - 1) / g_w.ws_col + 1)
		* g_w.ws_col;
	while (i <= size && matrix->right_limit < matrix->len - 1)
	{
		matrix->right_limit++;
		i += ((matrix->lines[matrix->right_limit]->symbols +
					get_lines_prompt_len(matrix->len) - 1) / g_w.ws_col + 1)
			* g_w.ws_col;
	}
	if (i > size && matrix->right_limit)
		matrix->right_limit--;
	return (0);
}

static int	change_limits_right_case(t_matrix *matrix, size_t new_right_limit)
{
	size_t	size;
	size_t	i;

	matrix->right_limit = new_right_limit;
	matrix->left_limit = new_right_limit;
	size = g_w.ws_row * g_w.ws_col;
	i = ((matrix->lines[matrix->left_limit]->symbols +
				get_lines_prompt_len(matrix->len) - 1) / g_w.ws_col + 1)
		* g_w.ws_col;
	while (i <= size && matrix->left_limit)
	{
		matrix->left_limit--;
		i += ((matrix->lines[matrix->left_limit]->symbols +
					get_lines_prompt_len(matrix->len) - 1) / g_w.ws_col + 1)
			* g_w.ws_col;
	}
	if (i > size)
		matrix->left_limit++;
	return (0);
}

static void	check_cursor_limits(t_matrix *matrix)
{
	size_t	left_limit;
	size_t	i;
	size_t	size;

	size = g_w.ws_row * g_w.ws_col;
	left_limit = matrix->cursor->row;
	i = ((matrix->lines[left_limit]->symbols +
				get_lines_prompt_len(matrix->len) - 1) / g_w.ws_col + 1)
		* g_w.ws_col;
	while (i <= size && left_limit)
	{
		left_limit--;
		i += ((matrix->lines[left_limit]->symbols +
					get_lines_prompt_len(matrix->len) - 1) / g_w.ws_col + 1)
			* g_w.ws_col;
	}
	if (i > size)
		left_limit++;
	if (left_limit > matrix->left_limit)
		change_limits_right_case(matrix, matrix->cursor->row);
}

int			set_matrix_limits(t_matrix *matrix)
{
	check_cursor_limits(matrix);
	if (matrix->cursor->row < matrix->left_limit)
		return (change_limits_left_case(matrix, matrix->cursor->row));
	if (matrix->cursor->row > matrix->right_limit)
		return (change_limits_right_case(matrix, matrix->cursor->row));
	return (change_limits_left_case(matrix, matrix->left_limit));
}
