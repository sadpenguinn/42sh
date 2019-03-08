/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:27:49 by nkertzma          #+#    #+#             */
/*   Updated: 2019/03/01 12:39:51 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "shell.h"

extern int		g_execerr;

void			xkill(void *cmd)
{
	kill(SIGINT, (int)cmd);
}

void			shell_handler(int sig)
{
	if (sig == SIGINT)
		dup2(0, 0);
	if (sig == SIGINT || sig == SIGQUIT || sig == SIGTSTP)
	{
		if (g_pids)
		{
			g_execerr = 1;
			vector_foreach(g_pids, xkill);
		}
	}
}

void			init_signals(void)
{
	struct sigaction	action;
	sigset_t			set;

	sigemptyset(&set);
	sigaddset(&set, SIGINT);
	sigaddset(&set, SIGQUIT);
	sigaddset(&set, SIGTSTP);
	ft_memset(&action, 0, sizeof(action));
	action.sa_handler = shell_handler;
	action.sa_mask = set;
	sigaction(SIGINT, &action, 0);
	sigaction(SIGQUIT, &action, 0);
	sigaction(SIGTSTP, &action, 0);
}
