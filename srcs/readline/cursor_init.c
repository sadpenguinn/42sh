/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 12:32:29 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/08 12:50:28 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "shell.h"

t_cursor	*cursor_init(void)
{
	t_cursor	*cursor;

	cursor = (t_cursor *)xmalloc(sizeof(t_cursor));
	cursor->row = 0;
	cursor->col = 0;
	return (cursor);
}
