/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:07:19 by nkertzma          #+#    #+#             */
/*   Updated: 2019/03/08 13:11:53 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	destroy_env(void)
{
	hash_clean(&g_hash_env);
	hash_clean(&g_hash_roenv);
	free_str_arr(&(g_env.env));
	free_str_arr(&(g_roenv.env));
}
