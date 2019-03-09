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

intmax_t	applay_unary(t_astree *root)
{
	if (root->type == EX_ADD)
		return (calc(root->left));
	if (root->type == EX_SUB)
		return (-calc(root->left));
	if (root->type == EX_LNOT)
		return ((intmax_t)!calc(root->left));
	if (root->type == EX_BNOT)
		return (~calc(root->left));
	return (0);
}

intmax_t	get_ques(t_astree *root)
{
	if (calc(root->left))
		return (calc(root->right->left));
	return (calc(root->right->right));
}

/*
**      (root0)EX_ASSIGN
**            /       \
**	(res)PREID         x(root1)
**                    / \
**      (expr2)EX_EXPR   NULL
*/

/* static char	*arith_var(char *var) */
/* { */
/* 	char	*content; */

/* 	content = sgetenv(var, ENV_ALL); */
/* 	if () */
/* } */

/* intmax_t	get_assign(t_astree *root) */
/* { */
/* 	intmax_t	tmp; */

/* 	tmp = calc(root->right->left); */
/* 	if (root->right->type == EX_ASSIGN) */
		
/* 	return (0); */
/* } */

intmax_t	calc(t_astree *root)
{
	if (!root)
		return (0);
	if (root->type == EX_NUM)
		return (ft_atoi(root->content));
	/* if (root->type == EX_VAR) */
	/* 	return (get_var(root->content)); */
	if (root->type == EX_QUES)
		return (get_ques(root));
	/* if (root->type == EX_ASSIGN) */
	/* 	return (get_assign(root)); */
	if (root->type == EX_ADD || root->type == EX_SUB || root->type == EX_LNOT ||
		root->type == EX_BNOT)
		return (applay_unary(root));
	if (root->type == EX_EXPR)
		return (operators[root->right->type - OPSHIFT](calc(root->left), root->right));
	return (-1488);
}
