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
#include <unistd.h>

void	ft_puts(char *buf)
{
	int	len;

	len = strlen(buf);
	write(1, buf, len);
}

void	init_readline(void)
{
	get_term_params(&g_w);
	history_fill();
}

t_string	*readline(void)
{
	int			ret;

	print_prompt();
	init_readline();
	set_term();
	ret = 1;
	while (ret > 0)
	{
		print_default(g_history->cur_matrix);
		ret = check_next_symbol();
	}
	if (ret == 0)
	{
		print_lines(g_history->cur_matrix);
		write(1, "\n", 1);
		matrix_to_string(g_history->cur_matrix, g_history->cur_matrix->str);
		if (history_save_elem())
			return (readline());
		unset_term();
		return (g_history->matrix[g_history->len - 1]->str);
	}
	history_del(&g_history);
	unset_term();
	return (NULL);
}
