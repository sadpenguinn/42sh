/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_and_debug.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:50:20 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/26 02:18:21 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conditions.h"

/*
** Global variables for parser
*/

void			*g_tokens = NULL;
unsigned int	g_curtok = 0;

// void	printmas(char **str)
// {
// 	int i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		free(str[i]);
// 		i++;
// 	}
// 	free(str);
// }

// int		main(void)
// {
// 	printf("%d\n", conditions(strsplit_to_conditions("")));
// 	return (0);
// }

int		main(int argc, char **argv, char **env)
{
	init_env(env, argv);
	(void)argc;
	(void)argv;
	printf("%d\n", conditions(strsplit_to_conditions("[ 1 ]")));
	destroy_env();
	return (0);
}