/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sunsetenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:04:15 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/16 15:08:05 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int 	sunsetenv(char *key)
{
	if (!key)
		return (0);
	return (hash_delete(key, g_hash_env, keyvaluecmp));
}