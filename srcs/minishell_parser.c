/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:34:08 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/23 12:44:48 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "builtins.h"
#include "libshell.h"

int				g_pid = 0;

static char		**build_argv(void *lexems, size_t i, size_t k)
{
	t_lexem	*lexem;
	char	**argv;
	size_t	size;
	int		p;

	p = 0;
	size = i - k;
	argv = (char **)xmalloc(sizeof(char *) * (size + 1));
	while (k < i)
	{
		lexem = (t_lexem *)vector_get_elem(lexems, k);
		argv[p] = ft_strvardup(lexem->word);
		p++;
		k++;
	}
	argv[p] = NULL;
	return (argv);
}

static void		fork_command(char **argv, char *path)
{
	int		status;

	g_pid = fork();
	if (g_pid == -1)
		sputerr(sstrerr(SHERR_CNTFRK));
	else if (g_pid == 0)
	{
		if (!(execve(path, argv, g_env)))
			exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(g_pid, &status, 0);
		g_pid = 0;
	}
}

static int		search_builtin(char **argv)
{
	if (!ft_strcmp(argv[0], "cd"))
		built_cd(argv, g_env);
	else if (!ft_strcmp(argv[0], "echo"))
		built_echo(argv, g_env);
	else if (!ft_strcmp(argv[0], "env"))
		built_env(argv, g_env);
	else if (!ft_strcmp(argv[0], "setenv"))
		built_setenv(argv, g_env);
	else if (!ft_strcmp(argv[0], "unsetenv"))
		built_unsetenv(argv, g_env);
	else if (!ft_strcmp(argv[0], "exit"))
		built_exit(argv, g_env);
	else
		return (0);
	return (1);
}

static void		exec_command(void *lexems, size_t i, size_t k)
{
	char	**argv;
	char	*path;

	argv = build_argv(lexems, i, k);
	if (search_builtin(argv))
		;
	else if (!(path = get_cmd_path(argv[0])))
		;
	else
		fork_command(argv, path);
	ft_strdel(&path);
	free_str_arr(&argv);
}

void			minishell_parser(void *lexems)
{
	t_lexem	*lexem;
	int		flag;
	size_t	len;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	flag = 0;
	len = vector_get_len(lexems);
	while (i < len)
	{
		lexem = vector_get_elem(lexems, i);
		if (lexem->type == SEMI)
		{
			flag = 1;
			exec_command(lexems, i, k);
			k = i + 1;
		}
		i++;
	}
	if (!flag)
		exec_command(lexems, i, k);
}
