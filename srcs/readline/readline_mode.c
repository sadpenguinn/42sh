/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:03:52 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/03 20:37:12 by sitlcead         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "libft.h"

int	readline_mode(t_uchar c)
{
	char		str[sizeof(t_uchar)];
	t_matrix	*matrix;

	if (c == CTRL_R)
	{
		g_search_mode = 1;
		return (1);
	}
	matrix = g_history->matrix[g_history->cur];
	if (are_default_shortcuts(matrix, c))
		return (1);
	if (c == BS)
		return (back_space(matrix));
	if (c == '\t' && g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] != CTRL_V)
		return (print_autocomplete(matrix));
	if (c == '\n')
		return (newline_handling(matrix));
	ft_memset(str, 0, sizeof(t_uchar));
	*matrix->cursor = matrix_string_insert(matrix, *matrix->cursor,
			str, symbol_to_string(c, str));
	return (1);
}
