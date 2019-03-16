/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:13:19 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/08 13:13:20 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include <stdlib.h>

void	matrix_free(t_matrix *matrix)
{
	size_t i;

	if (matrix == NULL)
		return ;
	cursor_free(matrix->cursor);
	string_free(matrix->str_history);
	modification_free(matrix->modif);
	i = 0;
	while (i < matrix->len)
		line_free(matrix->lines[i++]);
	free(matrix->lines);
	free(matrix);
}
