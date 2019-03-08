/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:58:56 by nkertzma          #+#    #+#             */
/*   Updated: 2019/03/01 17:01:58 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "lexer.h"
#include "parser.h"
#include "execute.h"

static void		exec_input(char *input)
{
	t_lexer		*lex;
	t_astree	*ast;

	lex = lexer(input, ft_strlen(input));
	g_tokens = lex->lexems;
	ast = inputunit();
	execute(ast);
	freeastree(ast);
	lexer_free(lex);
}

int				parse_input(int ac, char **av)
{
	char	*input;
	int		i;

	i = 2;
	input = ft_strnew(0);
	while (i < ac)
	{
		input = ft_strjoin(input, " ", 1);
		input = ft_strjoin(input, av[i], 1);
		i++;
	}
	exec_input(input);
	ft_strdel(&input);
	return (1);
}
