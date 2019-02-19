/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 20:52:46 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/19 20:53:17 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	destroy_path(void)
{
	hash_clean(g_path);
	hash_clean(g_path_sums);
	g_path = NULL;
	g_path_sums = NULL;
}
