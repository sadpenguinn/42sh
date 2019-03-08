/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <sitlcead@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:12:10 by sitlcead          #+#    #+#             */
/*   Updated: 2019/03/03 17:18:59 by sitlcead         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include <string.h>
#include "term.h"

void	init_readline(void)
{
	get_term_params(&g_w);
	set_term();
	g_heredoc = 1;
	print_prompt();
	history_fill();
}

t_string	*readline(void)
{
	int			ret;
	t_string	*str;

	init_readline();
	ret = 1;
	while (ret > 0)
	{
		if (g_search_mode)
			print_search(g_history->matrix[g_history->cur]);
		else
			print_default(g_history->matrix[g_history->cur]);
		ret = check_next_symbol();
	}
	if (ret == 0)
	{
		print_end(g_history->matrix[g_history->cur]);
		str = string_init();
		if (history_save(&str))
			return (readline());
		unset_term();
		return (str);
	}
	history_del(&g_history);
	unset_term();
	return (NULL);
}
