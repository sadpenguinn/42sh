/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:52:08 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/25 21:56:31 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	destroy_process(void)
{
	if (g_process)
	{
		free(g_process);
		g_process = NULL;
	}
}
