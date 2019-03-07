/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:02:32 by nkertzma          #+#    #+#             */
/*   Updated: 2019/01/23 11:23:42 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calc.h"

/*
* Missing EX_COND, EX_QUES, EX_COL, all ASSIGNments
* g_sherror must be declared in 42sh.c
*/

int			g_calcerr = 0;

intmax_t	calc(t_astree *root)
{
	if (root->type == EX_NUM)
		return (ft_atoi(root->content));
	/* if (root->type == EX_VAR) */
	/* 	return (get_var(root->content)); */
	if (root->type == EX_EXPR)
		return (operators[root->right->type - OPSHIFT](calc(root->left), root->right));
	return (0);
}
