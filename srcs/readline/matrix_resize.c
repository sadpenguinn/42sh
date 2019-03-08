/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <sitlcead@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:11:42 by sitlcead          #+#    #+#             */
/*   Updated: 2019/02/20 14:11:42 by sitlcead         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "shell.h"

void	matrix_resize(t_matrix *matrix, size_t new_size, size_t old_size)
{
	matrix->lines = (t_line **)xrealloc(matrix->lines,
			sizeof(t_line *) * new_size, sizeof(t_line *) * old_size);
	matrix->size = new_size;
}
