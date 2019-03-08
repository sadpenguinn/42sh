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

size_t	count_string_symbols(const char *buf, size_t col)
{
	size_t	i;
	size_t	symbols;

	i = 0;
	symbols = 0;
	while (i < col)
	{
		i += 1 + get_utf_offset_right(buf[i]);
		symbols++;
	}
	return (symbols);
}

size_t	count_string_cols(const char *buf, size_t symbols)
{
	size_t col;
	size_t i;

	col = 0;
	i = 0;
	while (i < symbols)
	{
		col += 1 + get_utf_offset_right(buf[col]);
		i++;
	}
	return (col);
}
