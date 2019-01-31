/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newline_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 20:32:08 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/29 20:37:17 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_astree	*newline_list(void)
{
	while (g_curtok >= ((size_t *)g_tokens)[2])
	{
		if (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type == NEWLINE)
			g_curtok++;
		else
			break ;
	}
	return (0);
}
