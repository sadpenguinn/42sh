/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_space_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 12:38:46 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/08 12:39:14 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	get_space_left_pos(const char *buf, size_t pos)
{
	while (pos && buf[pos - 1] != '\t' && buf[pos - 1] != ' ')
		pos--;
	return (pos);
}

size_t	get_space_right_pos(const char *buf, size_t pos, size_t len)
{
	while (pos < len && buf[pos] != '\t' && buf[pos] != ' ')
		pos++;
	return (pos);
}
