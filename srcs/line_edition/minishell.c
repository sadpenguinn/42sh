/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 23:11:22 by sitlcead          #+#    #+#             */
/*   Updated: 2019/01/17 11:14:59 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int		error_handling(int error)
{
	if (error == LINE_ALLOCATION_ERROR)
	{
		write(1, "LINE_ALLOCATION_FAILED", 22);
		exit(0);
	}
	if (error == HISTORY_ALLOCATION_ERROR)
	{
		write(1, "HISTORY_ALLOCATION_FAILED", 25);
		exit(0);
	}
	return (error);
}

int		end_of_line_handling(t_history *hst, t_line *line)
{
	hst->cur = hst->len - 1;
	if (hst->len > 1 && !strcmp(line->buf, hst->arr[hst->cur - 1]->buf))
		return (0);
	history_check_last(hst, line);
	check_history_reallocation(hst);
	hst->len++;
	hst->cur++;
	hst->arr[hst->cur] = create_line();
	return (0);
}

int		analyse_symbol(t_history *hst, t_line *line)
{
	t_uchar	c;

	/* time_t tmp = time(NULL); */
	/* printf("%zd", tmp - g_time); */
	/* fflush(stdout); */
	/* g_time = tmp; */
	c = get_next_symbol();
	/* printf("%llx\n", c); */
	/* fflush(stdout); */
	check_line_reallocation(line);
	c = (c == '\t') ? ' ' : c;
	if (c == '\n')
		return (end_of_line_handling(hst, line));
	if (history_handling(hst, line, c))
		return (1);
	return (check_modes(line->buf, &(line->len), &(line->pos), c));
}

void	print_prompt(void)
{
	write(1, "$> ", 3);
}

void	clear_term(void)
{
	write(1, "\ec", 2);
}

int		main(void)
{
	int			ret;
	t_line		*line;
	t_history	*hst;

	hst = create_history();
	line = create_line();
	g_prev_symbol = 0;
	while(1)
	{
		print_prompt();
		write(1, "$> ", 3);
		write(1, "\e[s", 3);
		g_mode = INSERT_MODE;
		/* write(1, "\033]2;-- INSERT --\007", 17); */
		/* g_time = time(NULL); */
		while ((ret = analyse_symbol(hst, line)))
				g_prev_symbol = ret;
		if (strcmp("exit", line->buf) == 0)
			break ;
		if (line->len)
			write(1, "\n", 1);
		write(1, line->buf, line->len);
		write(1, "\n", 1);
		free(line->buf);
		if (strcmp("clear", line->buf) == 0)
			clear_term();
		init_line(line);
	}
	write(1, "\n", 1);
	exit(0);
}
