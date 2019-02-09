/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_terminator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 15:06:32 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/09 18:52:26 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		list_terminator()
{
	t_type	type;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (TOKEOF);
	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type;
	if (type != NEWLINE && type != SEMI)
		return (0);
	g_curtok++;
	return (type);
}
