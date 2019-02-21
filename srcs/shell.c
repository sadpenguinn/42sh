/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:15:05 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/21 20:42:28 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** Global variables for parser
*/

void			*g_tokens = NULL;
unsigned int	g_curtok = 0;
int				g_parseerr = 0;

int		main(int ac, char **av, char **env)
{
	char 		*buf;
	t_lexer		*lex;
	t_astree	*ast;

	init(env);
	if (argv_parser(ac, av))
	{
		destroy();
		return (EXIT_SUCCESS);
	}
	while ((buf = readline()))
	{
		lex = lexer(buf, ft_strlen(buf));
		lexer_print(lex->lexems);
		g_tokens = lex->lexems;
		ast = inputunit();
		/*print_astree(ast);*/
		lexer_free(lex);
		ft_strdel(&buf);
	}
	destroy();
	return (EXIT_SUCCESS);
}
