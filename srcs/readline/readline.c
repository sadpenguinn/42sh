/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <sitlcead@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:12:10 by sitlcead          #+#    #+#             */
/*   Updated: 2019/02/24 16:49:36 by sitlcead         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include <string.h>
#include <unistd.h>
#include "term.h"

void     ft_puts(char *buf, int len)
{
	if (len == 0)
		len = strlen(buf);
	write(1, buf, len);
}

void	init_readline(t_matrix **matrix)
{
	get_term_params(&g_w);
	*matrix = init_matrix();
	g_mode = READLINE;
}

char	*readline(void)
{
	int			ret;
	t_matrix	*matrix;
	char		*str;

	print_prompt();
	init_readline(&matrix);
	set_term();
	ret = 1;
	while (ret > 0)
	{
		print_default(matrix);
		ret = check_next_symbol(matrix);
	}
	if (ret == 0)
	{
		print_lines(matrix);
		if (!(matrix->len == 1 && matrix->lines[0]->len == 0))
			write(1, "\n", 1);
		str = matrix_to_string(matrix);
	}
	else
		str = NULL;
	unset_term();
	matrix_del(&matrix);
	return (str);
}
