/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:54:49 by nkertzma          #+#    #+#             */
/*   Updated: 2019/03/25 13:54:51 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "lexer.h"
#include "parser.h"
#include "execute.h"

static int	exec_substitution(t_astree *root)
{
	int			fd[2];
	int			resfd;

	pipe(fd);
	resfd = fd[0];
	fd[0] = 0;
	if (g_dontexec == FALSE)
		if (root)
			execlist1(root, fd, 0);
	close(fd[1]);
	if (g_execerr || g_parseerr)
	{
		close(resfd);
		resfd = -1;
	}
	return (resfd);
}

int			substitution(char *cmd)
{
	t_lexer		*lex;
	t_astree	*ast;
	int			resfd;

	lex = lexer(cmd, ft_strlen(cmd));
	g_tokens = lex->lexems;
	resfd = -1;
	if ((ast = inputunit()))
		resfd = exec_substitution(ast);
	g_execerr = 0;
	freeastree(ast);
	lexer_free(lex);
	return (resfd);
}
