/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_and_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 20:35:33 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/02/24 20:35:36 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extention.h"

void	printmas(char **str)
{
	int i;

	i = 0;
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
	char *res;

	init_env(env);
	// hash_print(g_hash_env);
	// sgetenv("HOwqdqwME");
	//ssetenv("a", "a1 a2 a3 a4");
	if (argc != 3)
		printf("usage: %s '1/2' 'string'\n", argv[0]);
	else
	{
		if (ft_atoi(argv[1]) == 1)
		{
			res = expand(argv[2]);
			printf("res = %s\n", res);
			free(res);
		}
		if (ft_atoi(argv[1]) == 2)
			printmas(expand_v(argv[2]));
	}
	return (0);
}