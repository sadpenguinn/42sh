/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 09:00:43 by narchiba          #+#    #+#             */
/*   Updated: 2019/01/14 14:50:15 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

void		history_check_last(t_history *hst, t_line *line)
{
	if (hst->cur != hst->len - 1)
		return ;
	free(hst->arr[hst->cur]->buf);
	hst->arr[hst->cur]->len = line->len;
	hst->arr[hst->cur]->size = line->size;
	if (!(hst->arr[hst->cur]->buf = (char *)malloc(sizeof(char) * line->size)))
		error_handling(HISTORY_ALLOCATION_ERROR);
	memset(hst->arr[hst->cur]->buf, 0, line->size);
	memcpy(hst->arr[hst->cur]->buf, line->buf, line->len);
}

static void	line_replace(t_history *hst, t_line *line)
{
	clear_line(line->buf, &(line->len), &(line->pos));
	free(line->buf);
	line->len = hst->arr[hst->cur]->len;
	line->size = hst->arr[hst->cur]->size * RATIO;
	line->pos = line->len;
	if (!(line->buf = (char *)malloc(sizeof(char) * line->size)))
		error_handling(LINE_ALLOCATION_ERROR);
	memset(line->buf, 0, line->size);
	memcpy(line->buf, hst->arr[hst->cur]->buf, line->len);
	write(1, line->buf, line->len);
}

static void	history_up_case(t_history *hst, t_line *line)
{
	if (hst->cur == 0)
		return ;
	history_check_last(hst, line);
	hst->cur--;
	line_replace(hst, line);
}

static void	history_down_case(t_history *hst, t_line *line)
{
	if (hst->cur == hst->len - 1)
		return ;
	hst->cur++;
	line_replace(hst, line);
}

int			history_handling(t_history *hst, t_line *line, t_uchar c)
{
	if (c == UP || (c == 'k' && (g_mode & NORMAL_MODE)))
	{
		history_up_case(hst, line);
		return (1);
	}
	if (c == DOWN || (c == 'j' && (g_mode & NORMAL_MODE)))
	{
		history_down_case(hst, line);
		return (1);
	}
	return (0);
}
