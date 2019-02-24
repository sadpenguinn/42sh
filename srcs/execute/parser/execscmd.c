/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execscmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:31:00 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/20 18:58:20 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include <unistd.h>
#include "execute.h"
#include "libshell.h"

char *expand(char *str)
{
	char *new;

	new = ft_strdup(str);
	/* free(str); */
	return (new);
}
char **expandarg(char *str)
{
	char **new;

	new = malloc(sizeof(char *) * 2);
	new[0] = ft_strdup(str);
	new[1] = 0;
	/* free(str); */
	return (new);
}
/* char **get_alias(char *str) */
/* { */
/* 	char **new; */

/* 	new = malloc(sizeof(char *) * 3); */
/* 	new[0] = ft_strdup(str); */
/* 	new[1] = ft_strdup("-G"); */
/* 	new[2] = 0; */
/* 	/1* free(str); *1/ */
/* 	return (new); */
/* } */

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


int	get_cmd_attr(t_astree *root, t_list *cmd[3], int assignment)
{
	int			type;

	if (!root)
		return (0);
	type = root->left->type;
	if (type == WORD)
		assignment = 0;
	if (type == ASSIGMENT_WORD && !assignment)
		type = WORD;
	if (type != WORD && type != ASSIGMENT_WORD)
		ft_push_back(&cmd[2], get_redir(root->left));
	else
	{
		ft_push_back((type == WORD ? &cmd[0] : &cmd[1]), root->left->content);
		root->left->content = 0;
	}
	return (get_cmd_attr(root->right, cmd, assignment));
}

int		expand_assign(t_list *assign)
{
	char *bgn;
	char *res;
	char *val;

	while (assign)
	{
		val = (char *)assign->data;
		bgn = val;
		res = val;
		while (*val != '=')
			val++;
		val++;
		res = val;
		val = expand(val);
		*res = 0;
		res = ft_stradd(bgn, val, 1);
		assign->data = (void *)res;
		assign = assign->next;
	}
	return (0);
}

/* int		set_alias_arg(t_list **args) */
/* { */
/* 	int		i; */
/* 	char	*arg1; */
/* 	char	**alias; */

/* 	arg1 = (char *)(*args)->data; */
/* 	if (!(alias = get_alias(arg1))) */
/* 		return (0); */
/* 	free(ft_pop(args)); */
/* 	i = 0; */
/* 	while (alias[i]) */
/* 		i++; */
/* 	while (--i >= 0) */
/* 		ft_push(args, alias[i]); */
/* 	free(alias); */
/* 	return (0); */
/* } */

char	**get_argv(t_list *args)
{
	t_list	*lst;
	char	*arg;
	char	**argv;

	if (!args)
		return (0);
	lst = args;
	while (lst)
	{
		arg =(char *)lst->data;
		lst->data = (char **)expandarg(arg);
		free(arg);
		lst = lst->next;
	}
	argv = (char **)args->data;
	args->data = 0;
	while ((args = args->next))
	{
		argv = (char **)ft_joinvect((void **)argv, (void **)args->data, 1);
		args->data = 0;
	}
	return (argv);
}

char	**get_envp(t_list *envs)
{
	int		i;
	t_list	*lst;
	char	**envp;

	i = 0;
	lst = envs;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	envp = xmalloc(sizeof(char *) * (i + 1));
	i = 0;
	while (envs)
	{
		envp[i] = (char *)envs->data;
		envs = envs->next;
	}
	/* 	envp = (char **)ft_joinvect((void **)envp, (void **)g_env, 0); */
	return (envp);
}
int		execcommand(char **aven[2], t_list *redirs, int isfork)
{
	char	*path;
	t_redir	*redir;
	pid_t	pid;

	/* if (!(path = get_cmd_path([0][0]))) */
	/* 	return (1); */
if (!(path = ft_strjoin("/bin/", aven[0][0], 0)))
	return (1);
	if (!isfork && (pid = fork()))
		return (pid);
	while (redirs)
	{
		redir = (t_redir *)redirs->data;
		if (redir->type == REDIRECT)
			dup2(redir->fd[1], redir->fd[0]);
		if (redir->type == CLOSEFD)
			close(redir->fd[0]);
		redirs = redirs->next;
	}
	return (execve(path, aven[0], aven[1]));
}

int	set_envs(t_list	*envs)
{
	char	*val;

	while(envs)
	{
		val = (char *)envs->data; while (*val != '=')
			val++;
		*val++ = 0;
		/* ssetenv((char *)envs->data, val); */
		envs = envs->next;
	}
	return (EXIT_SUCCESS);
}

static void	initcmd(t_astree *root, int fd[2], t_list *cmd[3], char **aven[2])
{
	bzero(cmd, sizeof(t_list *) * 3);
	get_cmd_attr(root, cmd, 1);
	add_pipe_redir(&cmd[2], fd);
	expand_assign(cmd[1]);
	/* set_alias_arg(&cmd[0]); */
	aven[0] = get_argv(cmd[0]);
	aven[1] = get_envp(cmd[1]);
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
	/* else if  ((root = get_function(aven[0][0]))) */
	/* 	pid = function(root, aven[0], fd, job); */
	/* else if ((status = get_builtin(aven[0][0])) != -1) */
	/* 	pid = buitin(status, args); */
	else
		pid = execcommand(aven, cmd[2], isfork);
	freecmd(cmd, aven);
	if (pid == -1)
		return (forkerror(aven[0][0]));
	printf("***OK***\n");
	if (job || isfork)
		return (pid);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_FAILURE);
}
