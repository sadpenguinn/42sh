/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:15:05 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/27 13:42:38 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "execute.h"
#include "parser.h"

/*
** Global variables for parser
*/

void			*g_tokens = NULL;
unsigned int	g_curtok = 0;
int				g_parseerr = 0;

int		main(int ac, char **av, char **env)
{
	t_string	*line;
	t_lexer		*lex;
	t_astree	*ast;

	init(env);
	if (argv_parser(ac, av))
	{
		destroy();
		return (EXIT_SUCCESS);
	}
	while ((line = readline()))
	{
		lex = lexer(line->buf, line->len);
		string_del(&line);
		g_tokens = lex->lexems;
		ast = inputunit();
		if (g_dontexec == FALSE)
			execute(ast);
		freeastree(ast);
		lexer_free(lex);
	}
	destroy();
	return (EXIT_SUCCESS);
}
