/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical_operators.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:01:23 by nkertzma          #+#    #+#             */
/*   Updated: 2019/01/23 11:14:59 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

intmax_t	op_lor(intmax_t operator, t_astree *node)
{
	intmax_t	tmp;

	tmp = operator || execute(node->left);
	if (node->right)
		return (operators[node->right->type - OPSHIFT](tmp, node->right));
	return (tmp);
}

intmax_t	op_land(intmax_t operator, t_astree *node)
{
	intmax_t	tmp;

	tmp = operator && execute(node->left);
	if (node->right)
		return (operators[node->right->type - OPSHIFT](tmp, node->right));
	return (tmp);
}

intmax_t	op_neq(intmax_t operator, t_astree *node)
{
	intmax_t	tmp;

	tmp = operator != execute(node->left);
	if (node->right)
		return (operators[node->right->type - OPSHIFT](tmp, node->right));
	return (tmp);
}

intmax_t	op_eq(intmax_t operator, t_astree *node)
{
	intmax_t	tmp;

	tmp = operator == execute(node->left);
	if (node->right)
		return (operators[node->right->type - OPSHIFT](tmp, node->right));
	return (tmp);
}

intmax_t	op_leq(intmax_t operator, t_astree *node)
{
	intmax_t	tmp;

	tmp = operator <= execute(node->left);
	if (node->right)
		return (operators[node->right->type - OPSHIFT](tmp, node->right));
	return (tmp);
}

intmax_t	op_lt(intmax_t operator, t_astree *node)
{
	intmax_t	tmp;

	tmp = operator < execute(node->left);
	if (node->right)
		return (operators[node->right->type - OPSHIFT](tmp, node->right));
	return (tmp);
}

intmax_t	op_geq(intmax_t operator, t_astree *node)
{
	intmax_t	tmp;

	tmp = operator >= execute(node->left);
	if (node->right)
		return (operators[node->right->type - OPSHIFT](tmp, node->right));
	return (tmp);
}

intmax_t	op_gt(intmax_t operator, t_astree *node)
{
	intmax_t	tmp;

	tmp = operator > execute(node->left);
	if (node->right)
		return (operators[node->right->type - OPSHIFT](tmp, node->right));
	return (tmp);
}
