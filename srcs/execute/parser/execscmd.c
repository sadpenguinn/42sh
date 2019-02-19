/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execscmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:31:00 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/19 22:50:09 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include <unistd.h>
#include "execute.h"

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
char **get_alias(char *str)
{
	char **new;

	new = malloc(sizeof(char *) * 3);
	new[0] = ft_strdup(str);
	new[1] = ft_strdup("-G");
	new[2] = 0;
	/* free(str); */
	return (new);
}

int		add_pipe_redir(t_list **redlst, int fd[2])
{
	t_redir		*redir;

	redir = malloc(sizeof(t_redir) * 2);
	redir[0].type = REDIRECT;
	redir[1].type = REDIRECT;
	redir[0].fd[0] = STDIN_FILENO;
	redir[0].fd[1] = fd[0];
	redir[1].fd[0] = STDOUT_FILENO;
	redir[1].fd[1] = fd[1];
	ft_push(redlst, (void *)redir);
	ft_push(redlst, (void *)(redir + 1));
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

int		set_alias_arg(t_list **args)
{
	int		i;
	char	**alias;

	alias = get_alias(ft_pop(args));
	i = 0;
	while (alias[i])
		i++;
	while (--i >= 0)
		ft_push(args, alias[i]);
	free(alias);
	return (0);
}

char	**get_argv(t_list *args)
{
	t_list	*lst;
	char	**argv;

	set_alias_arg(&args);
	lst = args;
	while (lst)
	{
		lst->data = (char **)expandarg((char *)lst->data);
		lst = lst->next;
	}
	argv = (char **)args->data;
	args->data = 0;
	while ((args = args->next))
	{
		argv = (char **)ft_joinvect((void **)argv, (void **)args->data);
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
		envs->data = 0;
		envs = envs->next;
	}
	/* envs = ft_joinvect(envp, get_env()); */
	return (envp);
}
int		execute(char *path, char **argv, char **envp, t_list *redirs)
{
	t_redir	*redir;
	pid_t	pid;

	/* while (*argv) */
	/* 	printf("#argv:%s\n", *argv++); */
	/* while (*envp) */
	/* 	printf("#envp:%s\n", *envp++); */
	if ((pid = fork()))
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
	execve(path, argv, envp);

	return (0);
}

/*
**	cmd[0] - ARGRS
**	cmd[1] - ASSIGNMENT
**	cmd[2] - REDIRECTION
*/

int	execscmd(t_astree *root, int fd[2], int flag)
{
	t_list	*cmd[3];
	char	**argv;
	char	*path;
	char	**envp;
	pid_t	proc;

	bzero(cmd, sizeof(t_list *) * 3);
	get_cmd_attr(root, cmd, 1);
	/* add_pipe_redir(&cmd[2], fd); */
	expand_assign(cmd[1]);
	argv = get_argv(cmd[0]);
	envp = get_envp(cmd[1]);
	if (!(path = ft_strdup("/bin/ls")))
		return (0);
	/* if (!argv[0]) */
	/* 	return (set_envs(cmd[1])); */
	/* else */
		proc = execute(path, argv, envp, cmd[2]);
	if (!(flag & EX_JOB))
		proc = waitpid(proc, 0, 0);
	printf("***OK***\n");
	return (proc);
}

int main(void)
{
	t_astree	tree[100];
	int			fd[2];

	fd[0] = 0;
	fd[1] = 1;
	bzero(tree, sizeof(t_astree) * 100);

	tree[0].type = COMMAND;
	tree[0].left = &tree[50];
	tree[0].right = &tree[1];

	tree[1].type = COMMAND;
	tree[1].left = &tree[51];
	tree[1].right = &tree[2];

	tree[2].type = COMMAND;
	tree[2].left = &tree[52];
	tree[2].right = &tree[3];

	tree[3].type = COMMAND;
	tree[3].left = &tree[53];
	/* tree[3].right = &tree[4]; */
	tree[3].right = 0;

	/* tree[4].type = COMMAND; */
	/* tree[4].left = &tree[54]; */
	/* tree[4].right = &tree[5]; */

	/* tree[5].type = COMMAND; */
	/* tree[5].left = &tree[55]; */
	/* tree[5].right = 0; */

	tree[50].type = ASSIGMENT_WORD;
	tree[50].content = ft_strdup("A=3");

	tree[51].type = WORD;
	tree[51].content = ft_strdup("ls");

	tree[52].type = WORD;
	tree[52].content = ft_strdup("/Users/bwerewol");

	tree[53].type = WORD;
	tree[53].content = ft_strdup("dir2");

	/* tree[50].type = ASSIGMENT_WORD; */
	/* tree[50].content = ft_strdup("A=3"); */

	/* tree[51].type = WORD; */
	/* tree[51].content = ft_strdup("ls"); */

	/* tree[52].type = WORD; */
	/* tree[52].content = ft_strdup("/"); */

	/* tree[53].type = GREAT; */
	/* tree[53].right = &tree[75]; */
	/* tree[75].type = WORD; */
	/* tree[75].content = ft_strdup("file"); */

	/* tree[54].type = GREAT; */
	/* tree[54].right = &tree[76]; */
	/* tree[76].type = WORD; */
	/* tree[76].content = ft_strdup("file2"); */

	/* tree[55].type = WORD; */
	/* tree[55].content = ft_strdup("dir2"); */

	execscmd(&tree[0], fd, 0);
	return (0);
}
