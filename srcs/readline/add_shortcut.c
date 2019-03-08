/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_shortcuts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:58:07 by narchiba          #+#    #+#             */
/*   Updated: 2019/02/26 16:58:16 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

int	add_shortcut(t_uchar c)
{
	size_t	i;

	i = 0;
	while (i < SHORTCUT_ARRAY_SIZE - 1)
	{
		g_shortcuts[i] = g_shortcuts[i + 1];
		i++;
	}
	g_shortcuts[i] = c;
	return (1);
}
