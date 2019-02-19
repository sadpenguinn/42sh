/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execscmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:31:00 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/19 18:19:39 by bwerewol         ###   ########.fr       */
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
printf("rd:%d|%d\n", redir[0].fd[0], ((t_redir *)cmd[2]->data)->fd[1]);
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
printf("*%s\n", root->left->content);
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
		while (*val != '=')
			val++;
		*val++ = 0;
		val = expand(val);
		res = ft_strjoin(bgn, val, 3);
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

/* int		execute(char *path, char **argv, t_list *redirs) */
/* { */

/* } */

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
	pid_t	pid;

	bzero(cmd, sizeof(t_list *) * 3);
	add_pipe_redir(fd, &cmd[3]);
	/* get_cmd_attr(root, cmd, 1); */
	while (cmd[2])
	{
		printf("rd:%d|%d\n", ((t_redir *)cmd[2]->data)->fd[0], ((t_redir *)cmd[2]->data)->fd[1]);
		cmd[2] = cmd[2]->next;
	}
	/* expand_assign(cmd[1]); */
	/* argv = get_argv(cmd[0]); */
	/* path = get_path(argc[0]); */
	/* if ((pid = fork()) == -1) */
	/* 	return (-1); */
	/* if (!pid) */
	/* 	execute(path, argv, cmd[2]); */
	printf("***OK***\n");
	return (0);
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
	tree[3].right = &tree[4];

	tree[4].type = COMMAND;
	tree[4].left = &tree[54];
	tree[4].right = 0;

	tree[50].type = WORD;
	tree[50].content = "ls";

	tree[51].type = WORD;
	tree[51].content = "-l";

	tree[52].type = WORD;
	tree[52].content = "dir1";

	tree[53].type = GREAT;
	tree[53].right = &tree[75];
	tree[75].type = WORD;
	tree[75].content = "file";

	tree[54].type = LESS;
	tree[54].right = &tree[76];
	tree[76].type = WORD;
	tree[76].content = "file2";

	tree[55].type = WORD;
	tree[55].content = "dir2";

	execscmd(&tree[0], fd, 0);
	return (0);
}
