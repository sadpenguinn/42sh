/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_line_edition.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 23:17:17 by sitlcead          #+#    #+#             */
/*   Updated: 2019/01/30 17:49:30 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

static int	insert_letter(char *buf, int *len, int *pos, t_uchar c)
{
	int		offset;

	offset = 1;
	offset += (c >> 8) & 0xFF ? 1 : 0;
	offset += (c >> 16) & 0xFF ? 1 : 0;
	offset += (c >> 24) & 0xFF ? 1 : 0;
	if (*len - *pos)
		memcpy(buf + offset + *pos, buf + *pos, *len - *pos);
	*len += offset;
	buf[(*pos)++] = (c & 0xFF);
	if ((c >> 8) & 0xFF)
		buf[(*pos)++] = ((c >> 8) & 0xFF);
	if ((c >> 16) & 0xFF)
		buf[(*pos)++] = ((c >> 16) & 0xFF);
	if ((c >> 24) & 0xFF)
		buf[(*pos)++] = ((c >> 24) & 0xFF);
	past_symbols(1);
	write(1, &c, 4);
	return (1);
}

static void	del_left(char *buf, int *len, int *pos)
{
	int		offset;

	if (*pos == 0)
		return ;
	offset = 1;
	if ((buf[*pos - offset] >> 7) & 1)
		while (((buf[*pos - offset] >> 6) & 1) == 0)
			offset++;
	memmove(buf - offset + *pos, buf + *pos, *len - *pos);
	*len -= offset;
	buf[*len] = '\0';
	*pos -= offset;
	move_cursor_left(1);
	delete_symbols(1);
}

static void	del_right(char *buf, int *len, int *pos)
{
	int		offset;

	if (*pos == *len)
		return ;
	offset = 1;
	if ((buf[*pos] >> 7) & 1)
		while (((buf[*pos + offset] >> 7) & 1) && (((buf[*pos + offset] >> 6) & 1) == 0))
			offset++;
	memmove(buf + *pos, buf + *pos + offset, *len - *pos - offset);
	*len -= offset;
	buf[*len] = '\0';
	delete_symbols(1);
}

int		simple_line_edition(char *buf, int *len, int *pos, t_uchar c)
{
	if (c == BS)
	{
		del_left(buf, len, pos);
		return (1);
	}
	if (c == DEL)
	{
		del_right(buf, len, pos);
		return (1);
	}
	insert_letter(buf, len, pos, c);
	return (1);
}
