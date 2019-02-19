/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sunsetenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:04:15 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/19 18:56:29 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libshell.h"

int 	sunsetenv(char *key)
{
	if (hash_delete(key, g_hash_env) == HSH_ERR)
		return (SHERR_ERR);
	return (SHERR_OK);
}