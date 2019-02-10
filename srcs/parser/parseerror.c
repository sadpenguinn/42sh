/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseerror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:03:05 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/08 13:49:12 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_astree	*parseerror(void)
{
	t_lexem	*token;

	if (g_curtok >= ((size_t *)g_tokens)[2])
	{
		printf("42h: parse error near `%s'\n", "EOF");
		return (0);
	}
	token = ((t_lexem *)vector_get_elem(g_tokens, g_curtok));
	printf("42h: parse error near `%s'\n", token->word);
	return (0);
}
