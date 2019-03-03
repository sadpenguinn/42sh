/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:42:28 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/27 15:28:05 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

/*
** Exit
*/

int		built_exit(char **av, char **env)
{
	int 	ret;

	env = NULL;
	ft_putendl("Товарищ капитан, только на меня не спускайте, блядь.");
	if (av[1] && ft_str_is_numeric(av[1]))
	{
		ret = ft_atoi(av[1]);
		exit (ret);
	}
	exit(EXIT_SUCCESS);
}
