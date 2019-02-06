/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_and_line_allocation.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:02:13 by narchiba          #+#    #+#             */
/*   Updated: 2019/01/13 10:18:10 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

t_history	*create_history(void)
{
	t_history	*hst;

	if (!(hst = (t_history*)malloc(sizeof(t_history))))
		error_handling(HISTORY_ALLOCATION_ERROR);
	if (!(hst->arr = (t_line **)malloc(sizeof(t_line *) * HISTORY_SIZE)))
		error_handling(HISTORY_ALLOCATION_ERROR);
	hst->len = 1;
	hst->cur = 0;
	hst->size = HISTORY_SIZE;
	memset(hst->arr, 0, sizeof(t_line *) * HISTORY_SIZE);
	hst->arr[0] = create_line();
	return (hst);
}

void		init_line(t_line *line)
{
	if (!(line->buf = (char *)malloc(sizeof(char) * LINE_SIZE)))
		error_handling(LINE_ALLOCATION_ERROR);
	line->len = 0;
	line->pos = 0;
	line->size = LINE_SIZE;
	memset(line->buf, 0, LINE_SIZE);
}

t_line		*create_line(void)
{
	t_line	*line;
	if (!(line = (t_line *)malloc(sizeof(t_line))))
		error_handling(LINE_ALLOCATION_ERROR);
	init_line(line);
	return (line);
}

void		check_line_reallocation(t_line *line)
{
	char	*tmp;

	if (line->len < line->size - sizeof(int))
		return ;
	if (!(tmp = (char *)malloc(sizeof(char) * line->size * RATIO)))
		error_handling(LINE_ALLOCATION_ERROR);
	memset(tmp, 0, line->size * RATIO);
	memcpy(tmp, line->buf, line->len);
	free(line->buf);
	line->buf = tmp;
	line->size *= RATIO;
}

void		check_history_reallocation(t_history *hst)
{
	t_line	**tmp;

	if (hst->len < hst->size)
		return ;
	if (!(tmp = (t_line **)malloc(sizeof(t_line *) * hst->size * RATIO)))
		error_handling(HISTORY_ALLOCATION_ERROR);
	memset(tmp, 0, sizeof(t_line *) * hst->size * RATIO);
	memcpy(tmp, hst->arr, sizeof(t_line *) * hst->len);
	free(hst->arr);
	hst->arr = tmp;
	hst->size *= RATIO;
}
