/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <sitlcead@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:12:10 by sitlcead          #+#    #+#             */
/*   Updated: 2019/02/26 17:02:04 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include <string.h>
#include <unistd.h>
#include "term.h"
#include "libshell.h"

void	ft_puts(char *buf, int len)
{
	if (len == 0)
		len = strlen(buf);
	write(1, buf, len);
}

void	init_history(void)
{
	g_history = (t_history *)xmalloc(sizeof(t_history));
	g_history->matrix = (t_matrix **)xmalloc(HISTORY_DEFAULT_SIZE * sizeof(t_matrix *));
	g_history->size = HISTORY_DEFAULT_SIZE;
	g_history->len = 1;
	g_history->cur = 0;
	g_history->last_offset = 0;
	g_history->matrix[g_history->cur] = init_matrix();
}

void	history_resize(void)
{
	g_history->matrix =
			(t_matrix **)xrealloc(g_history->matrix,
								  g_history->size * RATIO * sizeof(t_matrix *),
								  g_history->size * sizeof(t_matrix *));
	g_history->size *= RATIO;
}

void	history_add_void_elem(void)
{
	if (g_history == NULL)
		init_history();
	else
	{
		if (g_history->size == g_history->len)
			history_resize();
		g_history->len++;
		g_history->cur = g_history->len - 1;
		g_history->matrix[g_history->cur] = init_matrix();
		g_history->last_offset = 0;
	}
}

void	init_readline(void)
{
	get_term_params(&g_w);
	history_add_void_elem();
	g_mode = READLINE;
}

void	history_add_elem(void)
{

}

char	*readline(void)
{
	int			ret;
	char		*str;

	print_prompt();
	init_readline();
	set_term();
	ret = 1;
	while (ret > 0)
	{
		print_default(g_history->matrix[g_history->cur]);
		ret = check_next_symbol(g_history->matrix[g_history->cur]);
	}
	if (ret == 0)
	{
		print_lines(g_history->matrix[g_history->cur]);
		write(1, "\n", 1);
		str = matrix_to_string(g_history->matrix[g_history->cur]);
	}
	else
		str = NULL;
	unset_term();
//	matrix_del(&matrix);
	return (str);
}
