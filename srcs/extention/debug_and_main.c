/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_and_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 20:35:33 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/26 17:12:36 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extention.h"
#include "shell.h"
#include "readline.h"
#include "lexer.h"
#include "parser.h"
#include "execute.h"

/*
** Global variables for parser
*/

void			*g_tokens = NULL;
unsigned int	g_curtok = 0;

void	printmas(char **str)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		printf("str[%d] = %s\n", i, str[i]);
		free(str[i]);
		i++;
	}
	free(str);
}

void	testing()
{
	char	*str;

	str = expand("echo ${SSH_AUTH_SOCK#/ssh}");
	// printf("        $HOME = %s\n", expand("test $hOME"));
	// printf("${HOME:-word} = %s\n", expand("test ${hOME:-word}"));
	printf("|%s|\n", str);
	free(str);
	// printf("${HOME:+word} = %s\n", expand("test ${hOME:+word}"));
	// printf("     ${#HOME} = %s\n", expand("test ${#hsOME}"));
	// printf("     ${HOME%%} = %s\n", expand("test ${hOME%}"));
	// printf("    ${HOME%%%%} = %s\n", expand("test ${hOME%%}"));
	// printf("     ${HOME#} = %s\n", expand("test ${hOME#}"));
	// printf("    ${HOME##} = %s\n", expand("test ${hOME##}"));
}

int		main(int argc, char **argv, char **env)
{
	// char *res;

	init_env(env, argv);
	// hash_print(g_hash_env);
	// sgetenv("HOwqdqwME");
	//ssetenv("a", "a1 a2 a3 a4");
	

	(void)argc;
	(void)argv;
	// testing();
	// printmas(expand_v("te\\ st"));

	// if (argc != 3)
	// 	printf("usage: %s '1/2' 'string'\n", argv[0]);
	// else
	// {
	// 	if (ft_atoi(argv[1]) == 1)
	// 	{
			// res = expand("$[5 / 0]");
			// printf("res = %s\n", res);
			// free(res);
	// 	}
	// 	if (ft_atoi(argv[1]) == 2)
	printmas(expand_v("echo ${SSH_AUTH_SOCK#/ssh}"));
	// }
	destroy_env();
	return (0);
}