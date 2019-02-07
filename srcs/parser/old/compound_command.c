/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compound_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:17:41 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/01 18:39:23 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
**              /
**   BRACE_GROUP
**  /           \
*/

#include "parser.h"

t_astree	*compound_command(void)
{
	int			type;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type;
	if (type == OBRACE)
		return (brace_group());
	else if (type == OBRACKET)
		return (subshell());
	else if (type == FOR)
		return (for_clause());
	else if (type == CASE)
		return (case_clause());
	else if (type == IF)
		return (if_clause());
	else if (type == WHILE)
		return (while_clause());
	else if (type == UNTIL)
		return (until_clause());
	return (0);
}
