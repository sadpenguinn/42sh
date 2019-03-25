/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initcmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:08:43 by bwerewol          #+#    #+#             */
/*   Updated: 2019/03/24 10:57:07 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "extention.h"

static int	g_initcmd_err;

static int	expand_assign(t_list *assign)
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
		val++;
		res = val;
		if (!(val = expand(val)))
			break ;
		*res = 0;
		res = ft_stradd(bgn, val, 1);
		assign->data = (void *)res;
		assign = assign->next;
	}
	if (assign)
		return (1);
	return (0);
}

static int	get_cmd_attr(t_astree *root, t_list *cmd[3], int assignment)
{
	int		type;
	t_redir	*redir;

	if (!root)
		return (0);
	type = root->left->type;
	if (type == WORD)
		assignment = 0;
	if (type == ASSIGMENT_WORD && !assignment)
		type = WORD;
	if (type != WORD && type != ASSIGMENT_WORD)
	{
		if ((redir = get_redir(root->left)))
			ft_push_back(&cmd[2], redir);
		else
			return (1);
	}
	else
	{
		ft_push_back((type == WORD ? &cmd[0] : &cmd[1]),
						ft_strdup(root->left->content));
	}
	return (get_cmd_attr(root->right, cmd, assignment));
}

static char	**get_argv(t_list *args)
{
	t_list	*lst;
	char	**argv;
	char	**tmp;

	if (!args)
		return (xmalloc(sizeof(char *)));
	lst = args;
	argv = xmalloc(sizeof(char *));
	while ((args))
	{
		if ((tmp = expand_v(args->data)))
			argv = (char **)ft_joinvect((void **)argv, (void **)tmp, 1);
		else
			g_initcmd_err = 1;
		// XXX free?
		/* free(arg); */
		args = args->next;
	}
	return (argv);
}

static char	**get_envp(t_list *envs)
{
	int		i;
	char	**envp;

	envp = xmalloc(sizeof(char *) * (ft_listlen(envs) + 1));
	i = 0;
	while (envs)
	{
		envp[i] = (char *)envs->data;
		envs = envs->next;
	}
	envp = (char **)ft_joinvect((void **)envp, (void **)g_env.env, 0);
	return (envp);
}

/*
** set_alias_arg(&cmd[0]);
*/

int			initcmd(t_astree *root, int fd[2], t_list *cmd[3], char **aven[2])
{
	bzero(cmd, sizeof(t_list *) * 3);
	add_pipe_redir(&cmd[2], fd);
	if (get_cmd_attr(root, cmd, 1))
		return (1);
	if (expand_assign(cmd[1]))
		return (1);
	set_alias_arg(&cmd[0]);
	aven[0] = get_argv(cmd[0]);
	if (g_initcmd_err)
	{
		ft_clearvect((void **)aven[0]);
		return (1);
	}
	aven[1] = get_envp(cmd[1]);
	g_sub_pids = vector_create(sizeof(pid_t));
	return (0);
}
