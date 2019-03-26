/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_and_debug.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:07:25 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/26 18:01:21 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "readline.h"
#include "lexer.h"
#include "parser.h"
#include "execute.h"
#include "autocomplete.h"

/*
** Global variables for parser
*/

void			*g_tokens = NULL;
unsigned int	g_curtok = 0;

void	printmas_delete(char **str)
{
	int i;

	i = 0;
	if (!str)
	{
		printf("Total NULL :(\n");
		return ;
	}
	while (str[i])
	{
		printf("str[%d] = %s\n", i, str[i]);
		i++;
	}
}

void	printmas(char **str)
{
	int i;

	i = 0;
	if (!str)
	{
		printf("Total NULL :(\n");
		return ;
	}
	while (str[i])
	{
		printf("str[%d] = %s\n", i, str[i]);
		free(str[i]);
		i++;
	}
	free(str);
}

int		main(int argc, char **argv, char **env)
{
	char	**res;
	char	*test;
	t_line	*line_info;

	argc++;
	test = ft_strdup("${LESS");
	(void)argv;
	init(env, argv);
	line_info = xmalloc(sizeof(t_line));
	line_info->buf = test;
	res = autocomplete(line_info, ft_strlen(test));
	printmas(res);
	free(test);
	free(line_info);
	destroy();
	return (0);
}
