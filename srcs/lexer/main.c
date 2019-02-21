/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 17:14:01 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/21 14:44:04 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "lexer.h"

int		main(int ac, char **av)
{
	t_lexer		*lex;

	if (ac != 2)
		return (1);
	lex = lexer(av[1], ft_strlen(av[1]));
	/*lex = lexer("((a(b)()()()wefemake()((wef   wef(((sfs(()ewf))wef    wef))wefwef))c))", 50);*/
	lexer_print(lex->lexems);
	return (0);
}
