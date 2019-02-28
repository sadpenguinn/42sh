/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:27:49 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/27 22:54:34 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

extern void		*g_pids;
extern int 		g_execerr;

void			xkill(void *cmd)
{
	kill(SIGINT, (int)cmd);
}

void			shell_handler(int sig)
{
	if (sig == SIGINT || sig == SIGQUIT || sig == SIGTSTP)
	{
		g_execerr = 1;
		vector_foreach(g_pids, xkill);
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
