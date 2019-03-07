/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_windows.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <sitlcead@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:12:23 by sitlcead          #+#    #+#             */
/*   Updated: 2019/02/20 14:12:23 by sitlcead         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "readline.h"

void	get_term_params(struct winsize	*w)
{
	ioctl(STDOUT_FILENO, TIOCGWINSZ, w);
	if (w->ws_col == 0 || w->ws_col == 0)
	{
		w->ws_col = 120;
		w->ws_row = 80;
	}
}

void	sig_handler(int signal)
{
	if (signal == SIGUSR1)
		write(1, "got\n", 4);
}

void	term_monitoring(pid_t pid)
{
	struct winsize	w;

	while (1)
	{
		get_term_params(&w);
		if (w.ws_row != g_w.ws_row || w.ws_col != g_w.ws_col)
		{
			kill(pid, SIGUSR1);
			g_w.ws_row = w.ws_row;
			g_w.ws_col = w.ws_col;
		}
	}
}
