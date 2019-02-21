/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:15:05 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/21 10:55:31 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** Global variables for parser
*/

void			*g_tokens = NULL;
unsigned int	g_curtok = 0;
int				g_parseerr = 0;

void	print_token(void *lexem)
{
	t_lexem		*lex;

	lex = (void *)lexem;
	if (lex->type != TERM_NEWLINE && lex->type != TERM_SPACE)
	{
		ft_putnbr(lex->type);
		ft_putstr(lex->word);
	}
	ft_putchar('$');
	ft_putchar('\n');
}

int		main(int ac, char **av, char **env)
{
	ac = 0;
	av = NULL;
	init(env);

	char 		*buf;
	t_lexer		*lex;
	t_astree	*ast;
	while ((buf = readline()))
	{
		lex = lexer(buf, ft_strlen(buf));
		vector_foreach(lex->lexems, print_token);
		g_tokens = lex->lexems;
		ast = inputunit();
		/*print_astree(ast);*/
		ft_putendl(buf);
		ft_strdel(&buf);
	}
	destroy();
	return (EXIT_SUCCESS);
}
