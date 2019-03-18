/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:20:46 by bwerewol          #+#    #+#             */
/*   Updated: 2019/03/13 11:14:16 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "execute.h"

int	g_execerr = 0;

int		pipeerror(void)
{
	ft_putstr_fd("42sh: pipe create error\n", STDERR_FILENO);
	g_execerr = -1;
	return (-1);
}

int		fileerror(char *file)
{
	ft_putstr_fd("42sh: can't open file : ", STDERR_FILENO);
	ft_putstr_fd(file, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	g_execerr = -1;
	return (-1);
}

int		forkerror(char *cmd)
{
	ft_putstr_fd("42sh: unable to fork : ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	g_execerr = 1;
	return (-1);
}

t_redir	*redirfileerror(char *file, t_redir *redir)
{
	free(redir);
	if (!g_execerr)
		fileerror(file);
	return ((t_redir *)0);
}

int		cmdexitsig(pid_t pid, int sig)
{
	if (sig == SIGINT)
		return (g_execerr = 1);
	ft_putnbr_fd(pid, STDERR_FILENO);
	if (sig == SIGSEGV)
		ft_putstr_fd("\tSegmentation fault\n", STDERR_FILENO);
	else if (sig == SIGABRT)
		ft_putstr_fd("\tAbort\n", STDERR_FILENO);
	else if (sig == SIGBUS)
		ft_putstr_fd("\tBus error\n", STDERR_FILENO);
	else if (sig == SIGFPE)
		ft_putstr_fd("\tFloating-point exception\n", STDERR_FILENO);
	else if (sig == SIGTSTP)
		ft_putstr_fd("\tsuspended\n", STDERR_FILENO);
	else
	{
		ft_putstr_fd("\tkilled\t(", STDERR_FILENO);
		ft_putnbr_fd(sig, STDERR_FILENO);
		ft_putstr_fd(")\n", STDERR_FILENO);
	}
	return (1);
}
