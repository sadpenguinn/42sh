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

/*
** Global variables with env and paths hashes/arrays
*/

t_hash			*g_hash_env = NULL;
t_hash			*g_hash_roenv = NULL;
t_hash			*g_path = NULL;
t_hash			*g_path_sums = NULL;
t_env			g_env;
t_env			g_roenv;

/*
** Global variables for saving jobs and processes
*/

void			*g_jobs = NULL;
void			*g_process = NULL;

void			*g_func = NULL;
void			*g_func_args = NULL;
int 			g_status = 0;

/*
** Defines for 'set' builtin witch modify the shell behavior
*/

int 			g_echoe = TRUE;
int 			g_dontexec = FALSE;

void	init(char **env)
{
	if (INITIAL_ENV_HASH_SIZE <= 0 || INITIAL_PATH_HASH_SIZE <= 0 ||
		INITIAL_PATH_SUMS_HASH_SIZE <= 0)
		die();
	init_env(env);
	init_path();
	/*init_jobs();
	init_process();*/
	init_pids();
	init_functions();
	init_function_args();
	init_signals();
}
