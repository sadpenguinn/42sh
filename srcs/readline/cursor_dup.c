/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 12:32:12 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/08 12:32:14 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "../lib/libshell/includes/libshell.h"

t_cursor	*cursor_dup(t_cursor *src)
{
	t_cursor	*dest;

	if (src == NULL)
		return (NULL);
	dest = (t_cursor *)xmalloc(sizeof(t_cursor));
	dest->row = src->row;
	dest->col = src->col;
	return (dest);
}
