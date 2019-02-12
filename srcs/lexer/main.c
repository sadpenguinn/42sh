/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 17:14:01 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/10 19:17:59 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "lexer.h"

void	print_token(void *lexem)
{
	t_lexem		*lex;

	lex = (void *)lexem;
	if (lex->type != TERM_NEWLINE && lex->type != TERM_SPACE)
		ft_putendl(lex->word);
}

int		main(int ac, char **av)
{
	t_lexer		*lex;

	if (ac != 3)
		return (1);
	lex = lexer(av[2], ft_atoi(av[1]));
	vector_foreach(lex->lexems, print_token);
	return (0);
}
