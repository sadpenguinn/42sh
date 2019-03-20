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
#include "signals.h"
#include "shell.h"
#include "readline.h"

extern int		g_execerr;

void			handle_sigtstp(int sig)
{
	(void)sig;
	/* printf("sigtstp handle\n"); */
}

void			handle_sigint(int sig)
{
	(void)sig;
	g_vi_mode = INSERT_MODE;
	g_execerr = 1;
	printf("sigint handle\n");
}

void			handle_sigin(int sig)
{
	(void)sig;
	tcsetpgrp(0, getpgid(getpid()));
}

void			init_signals(void)
{
	signal(SIGTSTP, handle_sigtstp);
	signal(SIGINT, handle_sigint);
	signal(SIGTTOU, SIG_IGN);
	signal(SIGTTIN, handle_sigin);
	signal(SIGCHLD, handle_sigchld);
}
