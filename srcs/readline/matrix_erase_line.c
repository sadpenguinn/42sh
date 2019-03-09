/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_erase_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:51:50 by narchiba          #+#    #+#             */
/*   Updated: 2019/02/26 16:51:52 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	matrix_erase_line(t_matrix *matrix, size_t row)
{
	if (matrix->len == 0)
		return ;
	line_del(&matrix->lines[row]);
	matrix->len--;
	if (row != matrix->len)
		ft_memmove(matrix->lines + row, matrix->lines + row + 1,
				(matrix->len - row) * sizeof(t_line *));
}
