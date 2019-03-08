/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execscmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:31:00 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/28 16:42:05 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include <unistd.h>
#include "execute.h"
#include "libshell.h"
#include "extention.h"

static int	g_cmdtype;

int			add_pipe_redir(t_list **redlst, int fd[2])
{
	t_redir		*redir[2];

	redir[0] = malloc(sizeof(t_redir));
	redir[1] = malloc(sizeof(t_redir));
	redir[0]->type = REDIRECT;
	redir[1]->type = REDIRECT;
	redir[0]->fd[0] = STDIN_FILENO;
	redir[0]->fd[1] = fd[0];
	redir[1]->fd[0] = STDOUT_FILENO;
	redir[1]->fd[1] = fd[1];
	ft_push_back(redlst, (void *)redir[0]);
	ft_push_back(redlst, (void *)redir[1]);
	return (0);
}

static int	execcommand(char **aven[2], t_list *redirs, int isfork)
{
	void	*cmd;
	pid_t	pid;

	if ((g_cmdtype = get_cmd_path(aven[0][0], &cmd)) == PATH_NULL)
		return (-1);
	if (g_cmdtype == PATH_NOFORK)
		return (((int (*)(char **, char **))cmd)(aven[0], aven[1]));
	if (!isfork && (pid = xfork()))
		return ((pid == -1) ? forkerror(aven[0][0]) : pid);
	applyredir(redirs);
	if (g_cmdtype == PATH_BIN)
		exit(execve((char *)cmd, aven[0], aven[1]));
	if (g_cmdtype == PATH_BUILT)
		exit(((int (*)(char **, char **))cmd)(aven[0], aven[1]));
	if (g_cmdtype == PATH_FUNC)
		exit(function((t_astree *)cmd, aven[0], aven[1]));
	exit(-1);
}

static int	freecmd(t_list *cmd[3], char **aven[2])
{
	int		i;
	t_list	*redirs;

	if (aven)
	{
		i = 0;
		while (aven[0][i])
			free(aven[0][i++]);
		free(aven[0]);
		free(aven[1]);
	}
	redirs = cmd[2];
	redirs = redirs->next->next;
	while (redirs)
	{
		if (((t_redir *)redirs->data)->fd[1] > 2)
			close(((t_redir *)redirs->data)->fd[1]);
		redirs = redirs->next;
	}
	ft_listdel(&cmd[0], &ft_free);
	ft_listdel(&cmd[1], &ft_free);
	ft_listdel(&cmd[2], &ft_free);
	return (0);
}

int			set_envs(t_list *envs)
{
	char	*val;

	while (envs)
	{
		val = (char *)envs->data;
		while (*val != '=')
			val++;
		*val++ = 0;
		ssetenv((char *)envs->data, val, ENV_RO);
		envs = envs->next;
	}
	return (EXIT_SUCCESS);
}

/*
**	cmd[0] - ARGRS
**	cmd[1] - ASSIGNMENT
**	cmd[2] - REDIRECTION
**
**	aven[0] - argv[][]
**	aven[1] - envp[][]
*/

int			execscmd(t_astree *root, int fd[2], int job, int isfork)
{
	t_list	*cmd[3];
	char	**aven[2];
	pid_t	pid;

	if (initcmd(root, fd, cmd, aven))
		return (freecmd(cmd, 0));
	if (!aven[0] || !aven[0][0])
		pid = set_envs(cmd[1]);
	else
		pid = execcommand(aven, cmd[2], isfork);
	freecmd(cmd, aven);
	if (pid == -1 || pid == 0)
		return (pid);
	if (g_cmdtype == PATH_NOFORK)
		return (pid);
	if (job || isfork)
		return (pid);
	return (xwaitpid(pid, 0));
}
