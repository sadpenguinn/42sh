/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:57:54 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/02/14 18:23:55 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

/*
**  sizes[0] - кол-во переменных
**  sizes[1] - кол-во перенаправлений
**  sizes[2] - кол-во аргументов
**	state - pipe(1) or background(0)
*/

void	print_tables(char **env, char **argv, t_table_exec **exec)
{
	int i;

	i = 0;
	ft_putstr("\n-----------------------------\nEnviroment:\n");
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	i = 0;
	ft_putstr("\nArgvs:\n");
	while (argv[i])
	{
		printf("%s\n", argv[i]);
		i++;
	}
	i = 0;
	ft_putstr("\nExec:\n");
	while (exec[i])
	{
		printf("Type: %d, content: %s, fd: %d\n", exec[i]->type,
					exec[i]->content, exec[i]->fd);
		i++;
	}
}
