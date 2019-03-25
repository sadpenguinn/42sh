/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_cmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:12:15 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/08 13:12:59 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "../lib/libshell/includes/libshell.h"

int	matrix_cmp(t_matrix *matrix1, t_matrix *matrix2)
{
	size_t	i;

	if (matrix1->len != matrix2->len)
		return (1);
	i = 0;
	while (i < matrix1->len)
	{
		if (matrix1->lines[i]->len != matrix2->lines[i]->len)
			return (1);
		if (ft_strcmp(matrix1->lines[i]->buf, matrix2->lines[i]->buf) != 0)
			return (1);
		i++;
	}
	return (0);
}
