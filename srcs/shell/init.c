/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:31:05 by nkertzma          #+#    #+#             */
/*   Updated: 2019/03/18 12:39:34 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "readline.h"
#include "lexer.h"
#include "parser.h"
#include "execute.h"
#include "autocomplete.h"

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
int				g_syntax = SYNTAX_OFF;

/*
**	Copy stdin descriptos
*/

int				g_stdin_fd;

void	init(char **env, char **av)
{
	if (INITIAL_ENV_HASH_SIZE <= 0 || INITIAL_PATH_HASH_SIZE <= 0 ||
		INITIAL_PATH_SUMS_HASH_SIZE <= 0)
		die();
	g_stdin_fd = dup(STDIN_FILENO);
	init_env(env, av);
	init_path();
	init_jobs();
	init_aliases();
	init_functions();
	init_function_args();
	init_signals();
	init_autocomplete();
	parse_config();
}
