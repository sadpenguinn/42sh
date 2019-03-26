/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_operators.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:07:50 by nkertzma          #+#    #+#             */
/*   Updated: 2019/01/23 11:17:40 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calc.h"

intmax_t	op_pow(intmax_t operator, t_astree *node)
{
	intmax_t	tmp;

	tmp = ft_pow(operator, calc(node->left));
	if (node->right)
		return (g_operators[node->right->type - OPSHIFT](tmp, node->right));
	return (tmp);
}

intmax_t	op_mul(intmax_t operator, t_astree *node)
{
	intmax_t	tmp;

	tmp = operator * calc(node->left);
	if (node->right)
		return (g_operators[node->right->type - OPSHIFT](tmp, node->right));
	return (tmp);
}

intmax_t	op_mod(intmax_t operator, t_astree *node)
{
	intmax_t	tmp;
	intmax_t	ret;

	if (!(ret = calc(node->left)))
		return (calcerror(CL_DIVZERO));
	tmp = operator % ret;
	if (node->right)
		return (g_operators[node->right->type - OPSHIFT](tmp, node->right));
	return (tmp);
}

intmax_t	op_div(intmax_t operator, t_astree *node)
{
	intmax_t	tmp;
	intmax_t	ret;

	if (!(ret = calc(node->left)))
		return (calcerror(CL_DIVZERO));
	tmp = operator / ret;
	if (node->right)
		return (g_operators[node->right->type - OPSHIFT](tmp, node->right));
	return (tmp);
}
