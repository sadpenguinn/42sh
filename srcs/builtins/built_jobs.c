/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:08:43 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/22 21:34:09 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "shell.h"

static void	print_pids(void *pid)
{
	ft_putstr(" ");
	ft_putnbr(*(pid_t *)pid);
}

int			built_jobs(char **av, char **env)
{
	size_t		len;
	size_t		i;
	t_job		*job;

	av = NULL;
	env = NULL;
	i = 0;
	len = vector_get_len(g_jobs);
	while (i < len)
	{
		job = (t_job *)vector_get_elem(g_jobs, i);
		ft_putstr("[");
		ft_putnbr(i + 1);
		ft_putstr("]");
		vector_foreach(job->pids, print_pids);
		ft_putstr("\n");
		i++;
	}
	return (SHERR_OK);
}
