/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <sitlcead@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 12:46:59 by sitlcead          #+#    #+#             */
/*   Updated: 2019/03/03 13:11:32 by sitlcead         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "shell.h"

t_matrix	*matrix_init(void)
{
	t_matrix	*matrix;

	matrix = (t_matrix *)xmalloc(sizeof(t_matrix));
	matrix->cursor = cursor_init();
	matrix->str_history = string_init();
	matrix->modif = modification_init();
	matrix->lines = (t_line **)xmalloc(sizeof(t_line *) * MATRIX_ARRAY_DEFAULT_SIZE);
	matrix->size = MATRIX_ARRAY_DEFAULT_SIZE;
	matrix->len = 0;
	matrix->left_limit = 0;
	matrix->right_limit = 0;
	return (matrix);
}
