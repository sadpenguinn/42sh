/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 11:01:49 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/20 15:17:28 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "autocomplete.h"
#include "libft.h"

static int	print_possibilities(t_matrix *matrix, char **matches, size_t cnt)
{
	size_t	i;

	set_matrix_limits(matrix);
	add_cursor_offset();
	add_lines_text(matrix);
	array_add("\n", 1);
	i = 0;
	while (i < cnt)
	{
		array_add(matches[i], ft_strlen(matches[i]));
		free(matches[i]);
		array_add("\n", 1);
		i++;
	}
	array_flush();
	print_prompt();
	reset_last_offset();
	free(matches);
	return (1);
}

int			print_autocomplete(t_matrix *matrix)
{
	char	**matches;
	size_t	cnt;

	matches = autocomplete(matrix->lines[matrix->cursor->row],
					matrix->cursor->col);
	if (matches == NULL)
		return (1);
	cnt = 0;
	while (matches[cnt])
		cnt++;
	if (cnt > 1)
		return (print_possibilities(matrix, matches, cnt));
	*matrix->cursor = matrix_string_insert(matrix, *matrix->cursor,
			matches[0], ft_strlen(matches[0]));
	free(matches[0]);
	free(matches);
	return (1);
}
