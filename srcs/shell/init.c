/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:31:05 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/21 18:23:50 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** Global variables with env and paths hashes/arrays
*/

t_hash			*g_hash_env = NULL;
t_hash			*g_path = NULL;
t_hash			*g_path_sums = NULL;
char			**g_env = NULL;

/*
** Global variables for saving jobs and processes
*/

void			*g_jobs = NULL;
void			*g_process = NULL;

void	shell_handler(int sig)
{
	if (sig == SIGBUS)
	{
		ft_putendl_fd("42sh: Bus error", 2);
		exit(EXIT_FAILURE);
	}
	if (sig == SIGFPE)
	{
		ft_putendl_fd("42sh: Illegal arithmetic operation", 2);
		exit(EXIT_FAILURE);
	}
	if (sig == SIGILL)
	{
		ft_putendl_fd("42sh: Illegal instruction", 2);
		exit(EXIT_FAILURE);
	}
	if (sig == SIGSEGV)
	{
		ft_putendl_fd("42sh: Segmentation fault", 2);
		exit(EXIT_FAILURE);
	}
	if (sig == SIGSYS)
	{
		ft_putendl_fd("42sh: Illegal system call", 2);
		exit(EXIT_FAILURE);
	}
	if (sig == SIGINT)
		ft_putendl("42sh: Ctrl-C");
	else if (sig == SIGQUIT)
		ft_putendl("42sh: Ctrl-\\");
	else if(sig == SIGTERM)
		ft_putendl("42sh: Sigterm");
	else if (sig == SIGTSTP)
		ft_putendl("42sh: Ctrl-Z");
}

void	init_signals(void)
{
	struct sigaction	act;
	sigset_t			set;

	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = shell_handler;
	sigemptyset(&set);
	sigaddset(&set, SIGBUS);
	sigaddset(&set, SIGFPE);
	sigaddset(&set, SIGILL);
	sigaddset(&set, SIGINT);
	sigaddset(&set, SIGKILL);
	sigaddset(&set, SIGQUIT);
	sigaddset(&set, SIGSEGV);
	sigaddset(&set, SIGTERM);
	sigaddset(&set, SIGTSTP);
	sigaddset(&set, SIGSYS);
	act.sa_mask = set;
	sigaction(SIGBUS, &act, 0);
	sigaction(SIGFPE, &act, 0);
	sigaction(SIGILL, &act, 0);
	sigaction(SIGINT, &act, 0);
	sigaction(SIGKILL, &act, 0);
	sigaction(SIGQUIT, &act, 0);
	sigaction(SIGSEGV, &act, 0);
	sigaction(SIGTERM, &act, 0);
	sigaction(SIGTSTP, &act, 0);
	sigaction(SIGSYS, &act, 0);
}

void	init(char **env)
{
	if (INITIAL_ENV_HASH_SIZE <= 0 || INITIAL_PATH_HASH_SIZE <= 0 ||
		INITIAL_PATH_SUMS_HASH_SIZE <= 0)
		die();
	init_env(env);
	init_path();
	init_jobs();
	init_process();
	init_signals();
}
