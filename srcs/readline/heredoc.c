/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 12:59:08 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/08 12:59:30 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include <string.h>
#include "term.h"
#include <unistd.h>

void		init_haredoc(void)
{
	dup2(0, 0);
	get_term_params(&g_w);
	set_term();
	g_heredoc = 1;
	history_fill();
}

t_string	*heredoc(void)
{
	int			ret;
	t_string	*str;

	init_haredoc();
	ret = 1;
	while (ret != 0)
	{
		if (g_search_mode)
			print_search(g_history->matrix[g_history->cur]);
		else
			print_default(g_history->matrix[g_history->cur]);
		ret = check_next_symbol();
	}
	print_end(g_history->matrix[g_history->cur]);
	str = string_init();
	matrix_to_string(g_history->matrix[g_history->cur], str);
	history_del(&g_history);
	unset_term();
	return (str);
}
