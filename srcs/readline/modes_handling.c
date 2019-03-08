/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modes_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:18:00 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/08 13:18:07 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

int			modes_handling(t_uchar c)
{
	add_shortcut(c);
	if (g_search_mode)
		return (search_mode(c));
	if (g_mode == READLINE)
		return (readline_mode(c));
	if (g_mode == VI)
		return (vi_mode(c));
	return (1);
}
