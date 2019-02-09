/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otherfunc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 18:46:14 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/09 18:50:20 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		checktype(t_type type)
{
	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (type == TOKEOF ? 1 : 0);
	if  (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type != type)
		return (0);
	g_curtok++;
	return (1);
}
