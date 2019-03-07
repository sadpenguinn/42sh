/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otherfunc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 18:46:14 by bwerewol          #+#    #+#             */
/*   Updated: 2019/03/01 21:27:58 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			checktype(t_type type)
{
	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (type == TOKEOF ? 1 : 0);
	if (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type != type)
		return (0);
	g_curtok++;
	return (1);
}

t_astree	*parseerror(t_astree *root)
{
	t_lexem	*token;

	freeastree(root);
	if (g_parseerr)
		return (0LU);
	g_parseerr = 1;
	if (g_curtok >= ((size_t *)g_tokens)[2])
	{
		ft_putstr_fd("\e[0;31m42sh: parse error near `EOF'\e[0m\n",
						STDERR_FILENO);
		return (0LU);
	}
	token = ((t_lexem *)vector_get_elem(g_tokens, g_curtok));
	ft_putstr_fd("\e[0;31m42sh: parse error near `", STDERR_FILENO);
	ft_putstr_fd(token->word, STDERR_FILENO);
	ft_putstr_fd("'\e[0m\n", STDERR_FILENO);
	return (0LU);
}

t_astree	*savecur(unsigned int cur, t_astree *root)
{
	freeastree(root);
	g_curtok = cur;
	return (0LU);
}

t_astree	*freeastree(t_astree *root)
{
	if (!root)
		return (0);
	if (root->content)
		free(root->content);
	if (root->left)
		freeastree(root->left);
	if (root->right)
		freeastree(root->right);
	free(root);
	return (0);
}
