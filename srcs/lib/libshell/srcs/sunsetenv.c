/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sunsetenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:04:15 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/28 16:33:28 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libshell.h"

/*
** Unset environment variable. If variable is found in hash table
** SHERR_OK will be returned, else - SHERR_ERR
*/

int		sunsetenv(const char *key)
{
	if (hash_delete(key, g_hash_env) == HSH_ERR)
		return (SHERR_ERR);
	free_str_arr(&g_env.env);
	g_env.size = 0;
	g_env.filled = 0;
	fill_genv();
	return (SHERR_OK);
}
