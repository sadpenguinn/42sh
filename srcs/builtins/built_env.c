/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:17:49 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/20 14:24:46 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

/*
** Just prints environment. If passed arguments, env display an error
*/

int 	built_env(char **av, char **env)
{
	if (av[1])
		ft_putendl_fd("env doesn't takes arguments", 2);
	else
		print_str_arr(env);
	return (HSH_OK);
}
