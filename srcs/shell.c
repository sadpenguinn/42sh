/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:15:05 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/24 12:07:16 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** Global variables for parser
*/

void			*g_tokens = NULL;
unsigned int	g_curtok = 0;
int				g_parseerr = 0;

#include "execute.h"


void	fff(char *k, char *v, void *d)
{
	printf("%s=%s=%s\n", k, v, (char *)d);
}

int		main(int ac, char **av, char **env)
{
	char		*buf;
	t_lexer		*lex;

	t_astree	*ast;

	init(env);



	t_hshtb	*ptr;
	size_t	size;
	size_t	i;

	i = 0;
	size = g_path->size;
	ptr = g_path->table;
	/* while (i < size) */
	/* { */
	/* 	if (ptr->key) */
	/* 		(fff)(ptr->key, ptr->value, ptr->data); */
	/* 	ptr++; */
	/* 	i++; */
	/* } */

	/* if (argv_parser(ac, av)) */
	/* { */
	/* 	destroy(); */
	/* 	return (EXIT_SUCCESS); */
	/* } */
	while ((buf = readline()))
	{
		lex = lexer(buf, ft_strlen(buf));
		lexer_print(lex->lexems);
		g_tokens = lex->lexems;
		ast = inputunit();
		execute(ast);
		lexer_free(lex);
		ft_strdel(&buf);
	}
	destroy();
	return (EXIT_SUCCESS);
}
