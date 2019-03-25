/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freepids.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:53:55 by nkertzma          #+#    #+#             */
/*   Updated: 2019/03/25 13:53:57 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "shell.h"

static void		killpids(void *data)
{
	pid_t pid;

	pid = *(pid_t *)data;
	kill(pid, SIGINT);
	waitpid(pid, 0, WUNTRACED);
}

void			freepids(void **pids)
{
	vector_foreach(*pids, killpids);
	vector_free(pids);
	*pids = 0;
}
