#include "execute.h"
#include "extention.h"

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

int		get_cmd_attr(t_astree *root, t_list *cmd[3], int assignment)
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
		arg = (char *)lst->data;
		lst->data = (char **)expand_v(arg);
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
	envp = (char **)ft_joinvect((void **)envp, (void **)g_env.env, 0);
	return (envp);
}

void	initcmd(t_astree *root, int fd[2], t_list *cmd[3], char **aven[2])
{
	bzero(cmd, sizeof(t_list *) * 3);
	get_cmd_attr(root, cmd, 1);
	add_pipe_redir(&cmd[2], fd);
	expand_assign(cmd[1]);
	/* set_alias_arg(&cmd[0]); */
	aven[0] = get_argv(cmd[0]);
	aven[1] = get_envp(cmd[1]);
}