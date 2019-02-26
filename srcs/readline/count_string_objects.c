/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_string_objects.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:46:11 by narchiba          #+#    #+#             */
/*   Updated: 2019/02/26 16:47:26 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

int	count_string_symbols(char *buf, int col)
{
	int	i;
	int	symbols;

	i = 0;
	symbols = 0;
	while (i < col)
	{
		i += 1 + get_utf_offset_right(buf[i]);
		symbols++;
	}
	return (symbols);
}

int	count_string_cols(char *buf, int symbols)
{
	int col;

	col = 0;
	while (symbols)
	{
		col += 1 + get_utf_offset_right(buf[col]);
		symbols--;
	}
	return (col);
}
