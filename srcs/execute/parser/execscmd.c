/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execscmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:31:00 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/18 19:05:07 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "execute.h"

typedef struct	s_redir
{
	char	*content;
	int		type;
	int		fd;
}				t_redir;

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

	new = malloc(sizeof(char *) * 2);
	new[0] = ft_strdup(str);
	new[1] = 0;
	/* free(str); */
	return (new);
}
/*
**              <(type)
**             /  \
**  (content)2?    filename(content)
*/

t_redir	*get_redir(t_astree *root)
{
	t_redir		*redir;
	int			type;

	type = root->type;
	redir = malloc(sizeof(t_redir));
	redir->type = type;
	redir->content = root->right->content;
	root->right->content = 0;
	redir->fd = (type == LESS || type == DLESS || type == LESSAND) ? 0 : 1;
	if (root->left)
		redir->fd = ft_atoi(root->left->content);
	return (redir);
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

	alias = get_alias(ft_pop(&args));
	i = 0;
	while (alias[i])
		i++;
	while (--i <= 0)
		ft_push_back(args, alias[i]);
	free(alias);
	return (0);
}

char	**get_argv_list(t_list *args)
{
	t_list	*lst;

	set_alias_arg(&args);
	lst = args;
	while (lst)
	{
		lst->data = (char **)expandarg((char *)lst->data);
		lst = lst->next;
	}
}

int	execscmd(t_astree *root, int fd[2], int flag)
{
	t_list	*cmd[3]; //[0]-WORD [1]-ASSIGMENT [2]-REDIRECTION
	char	**argv;

	bzero(cmd, sizeof(t_list *) * 3);
	get_cmd_attr(root, cmd, 1);
	expand_assign(cmd[0]);
	argv = get_argv_list(cmd[1]);

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

	tree[51].type = WORD;
	tree[51].content = "ls";

	tree[52].type = WORD;
	tree[52].content = "-l";

	tree[53].type = GREAT;
	tree[53].content = ">";
	tree[53].right = &tree[75];
	tree[75].type = WORD;
	tree[75].content = "file";

	tree[54].type = WORD;
	tree[54].content = "ls";

	execscmd(&tree[0], fd, 0);
	return (0);
}
