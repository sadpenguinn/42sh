/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:31:05 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/19 20:55:52 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** Global variables with env and paths hashes/arrays
*/
t_hash			*g_hash_env = NULL;
t_hash			*g_path = NULL;
t_hash			*g_path_sums = NULL;
char 			**g_env = NULL;

void	init(char **env)
{
	init_env(env);
/*	init_path();*/
}
