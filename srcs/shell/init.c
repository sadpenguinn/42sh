/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:31:05 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/25 21:56:31 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "readline.h"

/*
** Global variables with env, aliases and paths hashes/arrays.
** 'roenv' arrays stores only read-only variables
*/

t_hash			*g_hash_env = NULL;
t_hash			*g_hash_roenv = NULL;
t_hash			*g_path = NULL;
t_hash			*g_path_sums = NULL;
t_alias			*g_aliases = NULL;
t_env			g_env;
t_env			g_roenv;

/*
** Global variables for saving jobs and pids
** of running processes to kill them
*/

void			*g_jobs = NULL;
void			*g_pids = NULL;

/*
** Vectors which stores functions trees and them arguments
*/

void			*g_func = NULL;
void			*g_func_args = NULL;

/*
** Global variables with status of previous operation - $?
*/

int				g_status = 0;

/*
** Defines for 'set' builtin witch modify the shell behavior
*/

int				g_echoe = TRUE;
int				g_dontexec = FALSE;
int				g_syntax = SYNTAX_ON;

#include "lexer.h"
#include "parser.h"
#include "execute.h"

void	parse_config(void)
{
	char		*script;
	t_lexer		*lex;
	t_astree	*ast;
	size_t		len;
	char		*path;
	int			fd;

	path = ft_strjoin(sgetenv("HOME", ENV_ALL), SHELL_DEFAULT_RC, 0);
	fd = open(path, O_CREAT, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR);
	close(fd);
	len = get_file_size(path);
	script = (char *)xmalloc((sizeof(char) * (len + 1)));
	fd = open(path, 'r');
	read(fd, script, len + 1);
	close(fd);
	ft_strdel(&path);
	lex = lexer(script, len);
	ft_strdel(&script);
	g_tokens = lex->lexems;
	ast = inputunit();
	execute(ast);
	freeastree(ast);
	lexer_free(lex);
}

void	init(char **env)
{
	if (INITIAL_ENV_HASH_SIZE <= 0 || INITIAL_PATH_HASH_SIZE <= 0 ||
		INITIAL_PATH_SUMS_HASH_SIZE <= 0)
		die();
	init_env(env);
	init_path();
	init_jobs();
	init_pids();
	init_aliases();
	init_functions();
	init_function_args();
	init_signals();
	parse_config();
}
