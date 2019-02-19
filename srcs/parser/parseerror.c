/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseerror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:03:05 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/15 15:28:17 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_astree	*parseerror(void)
{
	t_lexem	*token;

	if (g_parseerr)
		return (0);
	g_parseerr = 1;
	if (g_curtok >= ((size_t *)g_tokens)[2])
	{
		printf("\e[0;31m42h: parse error near `%s'\n\e[0m", "EOF");
		return (0);
	}
	token = ((t_lexem *)vector_get_elem(g_tokens, g_curtok));
	printf("\e[0;31m42h: parse error near `%s'\e[0m\n", token->word);
	return (0);
}
