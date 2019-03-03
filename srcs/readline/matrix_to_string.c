/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_to_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:55:52 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/03 15:29:14 by sitlcead         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "libft.h"
#include <stdio.h>

void	matrix_to_string(t_matrix *matrix, t_string *str)
{
	int	i;

	i = 0;
	while (i < matrix->len - 1)
	{
		array_add(matrix->lines[i]->buf, matrix->lines[i]->len);
		i++;
	}
	array_add(matrix->lines[i]->buf, matrix->lines[i]->len);
	free(str->buf);
	str->buf = array_to_string();
	str->len = ft_strlen(str->buf);
}
