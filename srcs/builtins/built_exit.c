/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:42:28 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/25 18:11:23 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

/*
** Exit
** Need to add handling of running processes
*/

int		built_exit(char **av, char **env)
{
	av = NULL;
	env = NULL;
	ft_putendl("Товарищ капитан, только на меня не спускайте, блядь.");
	exit(EXIT_SUCCESS);
}
