/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_operators.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:07:50 by nkertzma          #+#    #+#             */
/*   Updated: 2019/01/22 19:40:44 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

intmax_t	op_sub(intmax_t operator, t_astree *node)
{
	intmax_t	tmp;

	tmp = operator - execute(node->left);
	if (node->right)
		return (operators[node->right->type - OPSHIFT](tmp, node->right));
	return (tmp);
}

intmax_t	op_add(intmax_t operator, t_astree *node)
{
	intmax_t	tmp;

	tmp = operator + execute(node->left);
	ft_putnbrendl(tmp);
	if (node->right)
		return (operators[node->right->type - OPSHIFT](tmp, node->right));
	return (tmp);
}
