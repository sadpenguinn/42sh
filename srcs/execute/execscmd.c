/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execscmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:31:00 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/27 22:45:42 by nkertzma         ###   ########.fr       */
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

int		add_pipe_redir(t_list **redlst, int fd[2])
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
	ft_push(redlst, (void *)redir[0]);
	ft_push(redlst, (void *)redir[1]);
	return (0);
}

int		execcommand(char **aven[2], t_list *redirs, int isfork)
{
	void 	*cmd;
	int		cmdtype;
	t_redir	*redir;
	pid_t	pid;

	if ((cmdtype = get_cmd_path(aven[0][0], &cmd)) == PATH_NULL)
		return (-1);
	if (cmdtype == PATH_EXIT)
		exit(0);
	if (!isfork && (pid = xfork()))
		return ((pid == -1) ? forkerror(aven[0][0]) : pid);
	while (redirs)
	{
		redir = (t_redir *)redirs->data;
		if (redir->type == REDIRECT)
			dup2(redir->fd[1], redir->fd[0]);
		if (redir->type == CLOSEFD)
			close(redir->fd[0]);
		redirs = redirs->next;
	}
	if (cmdtype == PATH_BIN)
		return (execve((char *)cmd, aven[0], aven[1]));
	if (cmdtype == PATH_BUILT)
		return (((int (*)(char **, char **))cmd)(aven[0], aven[1]));
	return (-1);
}

static void	freecmd(t_list *cmd[3], char **aven[2])
{
	int		i;
	t_list	*redirs;

	i = 0;
	while (aven[0][i])
		free(aven[0][i++]);
	free(aven[0]);
	free(aven[1]);
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
}

int		set_envs(t_list *envs)
{
	char	*val;

	while (envs)
	{
		val = (char *)envs->data;
		while (*val != '=')
			val++;
		*val++ = 0;
		ssetenv((char *)envs->data, val);
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

int	execscmd(t_astree *root, int fd[2], int job, int isfork)
{
	t_list	*cmd[3];
	char	**aven[2];
	pid_t	pid;
	int		status;

	initcmd(root, fd, cmd, aven);
	if (!aven[0])
		return (set_envs(cmd[1]));
	else
		pid = execcommand(aven, cmd[2], isfork);
	freecmd(cmd, aven);
	if (pid == -1)
		return (-1);
	if (job || isfork)
		return (pid);
	xwaitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (cmdexitsig(pid, WTERMSIG(status)));
	return (EXIT_FAILURE);
}
