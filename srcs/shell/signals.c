/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:27:49 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/24 17:18:50 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	shell_handler(int sig)
{
	if (sig == SIGINT || sig == SIGQUIT || sig == SIGTSTP)
		exit(EXIT_SUCCESS);
}

void	init_signals(void)
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
