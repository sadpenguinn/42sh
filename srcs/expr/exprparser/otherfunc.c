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

#include "expr.h"
#include "expression.h"

int			checktype(t_type type)
{
	if (g_excurtok >= ((size_t *)g_extokens)[2])
		return (type == TOKEOF ? 1 : 0);
	if (((t_lexem *)vector_get_elem(g_extokens, g_excurtok))->type != type)
		return (0);
	g_excurtok++;
	return (1);
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

t_astree	*savecur(unsigned int cur, t_astree *root)
{
	freeastree(root);
	g_excurtok = cur;
	return (0LU);
}

t_astree	*parseerror(t_astree *root)
{
	t_lexem	*token;

	freeastree(root);
	if (g_exprerr)
		return (0LU);
	g_exprerr = 1;
	if (g_excurtok >= ((size_t *)g_extokens)[2])
	{
		ft_putstr_fd(
				"\e[0;31mExpression: error near `expresson end'\e[0m\n",
				STDERR_FILENO);
		return (0LU);
	}
	token = ((t_lexem *)vector_get_elem(g_extokens, g_excurtok));
	ft_putstr_fd("\e[0;31mExpression: error near `", STDERR_FILENO);
	ft_putstr_fd(token->word, STDERR_FILENO);
	ft_putstr_fd("'\e[0m\n", STDERR_FILENO);
	return (0LU);
}
