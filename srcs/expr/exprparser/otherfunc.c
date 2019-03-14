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

int			exchecktype(t_type type)
{
	if (g_excurtok >= ((size_t *)g_extokens)[2])
		return (type == TOKEOF ? 1 : 0);
	if (((t_lexem *)vector_get_elem(g_extokens, g_excurtok))->type != type)
		return (0);
	g_excurtok++;
	return (1);
}

t_astree	*exfreeastree(t_astree *root)
{
	if (!root)
		return (0);
	if (root->content)
		free(root->content);
	if (root->left)
		exfreeastree(root->left);
	if (root->right)
		exfreeastree(root->right);
	free(root);
	return (0);
}

t_astree	*exsavecur(unsigned int cur, t_astree *root)
{
	exfreeastree(root);
	g_excurtok = cur;
	return (0LU);
}

t_astree	*exparseerror(t_astree *root)
{
	t_lexem	*token;

	exfreeastree(root);
	if (g_exprerr)
		return (0LU);
	g_exprerr = 1;
	ft_putstr_fd("\e[0;31m", STDERR_FILENO);
	ft_putstr_fd("42sh: ", STDERR_FILENO);
	ft_putstr_fd("bad math expression: error near `", STDERR_FILENO);
	token = (g_excurtok >= ((size_t *)g_extokens)[2]) ?
				0 : ((t_lexem *)vector_get_elem(g_extokens, g_excurtok));
	ft_putstr_fd((token ? token->word : "END OF STRING"), STDERR_FILENO);
	ft_putstr_fd("'\e[0m\n", STDERR_FILENO);
	return (0LU);
}
