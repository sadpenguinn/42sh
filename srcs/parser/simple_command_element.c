/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command_element.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 20:49:39 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/10 21:46:19 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** SCE - Simple Command Element
**
**     SCE(word) of REDIRECTION
*/

#include "parser.h"

static t_astree	*get_assigment(void)
{
	t_type		type;
	t_lexem		*token;
	t_astree	*root;

	token = ((t_lexem *)vector_get_elem(g_tokens, g_curtok));
	type = token->type;
	if (!check_word_type(type))
		return (0);
	if (!check_assigment_word(token->word))
		return (0);
	root = xmalloc(sizeof(t_astree));
	root->type = ASSIGMENT_WORD;
	root->content = ft_strdup(token->word);
	g_curtok++;
	return (root);
}

static t_astree	*get_word(void)
{
	t_type		type;
	t_lexem		*token;
	t_astree	*root;

	token = ((t_lexem *)vector_get_elem(g_tokens, g_curtok));
	type = token->type;
printf("type = %lu\n", type);
	if (!check_word_type(type))
		return (0);
printf("check type:%d\n", check_word_type(type));
printf("type = %lu\n", type);
	root = xmalloc(sizeof(t_astree));
	root->content = ft_strdup(token->word);
	root->type = WORD;
	g_curtok++;
	return (root);
}

t_astree	*simple_command_element(void)
{
	t_astree	*res;

	if ((res = redirection()))
		return (res);
	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	if ((res = get_assigment()))
		return (res);
	if ((res = get_word()))
		return (res);
	return (0);
}
