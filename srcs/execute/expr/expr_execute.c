/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:02:32 by nkertzma          #+#    #+#             */
/*   Updated: 2019/01/22 19:41:31 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

intmax_t	execute(t_astree *root)
{
	if (root->type == NUM)
		return (ft_atoi(root->content));
	if (root->type == VAR)
		return (get_var(root->content));
	if (root->type == PREINC || root->type == PREDEC ||
		root->type == UPLUS || root->type UMINUS ||
		root->type == LNOT || root->type BNOT)
		return (get_prefix(root));
	if (root->type == EXPR)
		return (operators[root->right->type - OPSHIFT](execute(root->left), root->right));
	return (0);
}
