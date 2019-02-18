/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execcmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:36:43 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/02/14 18:28:21 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	counter(t_astree *root, int *sizes)
{
	if (!root)
		return ;
	counter(root->left, sizes);
	if (root->type == ASSIGMENT_WORD)
		sizes[0]++;
	if (root->type >= LESS && root->type <= TLESS)
		sizes[1]++;
	if (root->type == WORD)
		sizes[2]++;
	counter(root->right, sizes);
}

void	filling_data(t_astree *root, char **env, char **argv,
						t_table_exec **exec)
{
	if (!root)
		return ;
	if (root->left->type == ASSIGMENT_WORD)
	{
		env[0] = get_extension(root->left->content);
		filling_data(root->right, &(env[1]), argv, exec);
	}
	else if (root->left->type >= LESS && root->left->type <= TLESS)
	{
		exec[0]->type = root->left->type;
		exec[0]->content = ft_strdup(root->left->right->content);
		exec[0]->fd = (root->left->type == GREAT) ? 0 : 1;
		filling_data(root->right, env, argv, &(exec[1]));
	}
	else if (root->left->type == WORD)
	{
		argv[0] = ft_strdup(root->left->content);
		filling_data(root->right, env, &(argv[1]), exec);
	}
	else
	{
		printf("!!!!! Something is wrong, type=%d, content=%s.\n",
				root->type, root->content);
		filling_data(root->right, env, argv, exec);
	}
}

void	xmalloc_data(int *sizes, char ***env,
						t_table_exec ***redir_t, char ***argv)
{
	int i;

	*env = xmalloc(sizeof(char **) * (sizes[0] + 1));
	*redir_t = xmalloc(sizeof(t_table_exec*) * (sizes[1] + 1));
	*argv = xmalloc(sizeof(char *) * (sizes[2] + 1));
	i = 0;
	while (i < sizes[1] + 1)
	{
		*redir_t[i] = xmalloc(sizeof(t_table_exec));
		i++;
	}
}

/*
**  sizes[0] - кол-во переменных
**  sizes[1] - кол-во перенаправлений
**  sizes[2] - кол-во аргументов
**	state - pipe(1) or background(0)
*/

void	processing_tables(char **env, char **argv, t_table_exec **exec)
{
	int i;

	i = 0;
	if (!check_bin_in_path(argv[0]))
	{
		ft_putstr("Command not found\n");
		exit(0);
	}
	while (exec[i])
	{
		switcher_in_processing(exec[i]);
		i++;
	}
	configure_and_run_execv(env, argv, exec);
	env++;
	exec++;
}

/*
**	fd[0]stdin fd[1]stdout
*/

int		execcmd(t_astree *root, int fd[2], int pipeand, int job)
{
	int					sizes[3];
	char				**env;
	char				**argv;
	t_table_exec		**table_exec;

	(void)fd;
	(void)pipeand;
	(void)job;
	env = NULL;
	ft_bzero(sizes, sizeof(int) * 3);
	counter(root, sizes);
	printf("vars: %d,\nredi: %d,\nexec: %d.\n", sizes[0], sizes[1], sizes[2]);
	xmalloc_data(sizes, &env, &table_exec, &argv);
	filling_data(root, env, argv, table_exec);
	print_tables(env, argv, table_exec);
	processing_tables(env, argv, table_exec);
	return (0);
}
