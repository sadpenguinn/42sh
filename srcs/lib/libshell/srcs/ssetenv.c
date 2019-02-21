/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssetenv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:50:20 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/21 15:31:10 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libshell.h"

int 	ssetenv(const char *key, const char *value)
{
	char 	*str;

	if (!key)
		return (SHERR_ERR);
	str = ft_strjoin(key, "=", 0);
	if (value)
		str = ft_strjoin(str, value, 1);
	if ((hash_insert(key, value, g_hash_env, str) == HSH_ERR))
	{
		free(str);
		return (SHERR_ERR);
	}
	free(str);
	return (SHERR_OK);
}
