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
**     (root)EX_ASSIGN
**          /         \
**	(r-l)VAR           x
**                    / \
**       (expr)EX_EXPR   NULL
*/

intmax_t	get_assign(t_astree *root)
{
	intmax_t	tmp;
	char		*var;
	char		*val;

	val = ft_itoa(calc(root->right->left));
	if (!(var = get_pre_incdec(root->left)))
		return (0);
	if (root->right->type != EX_ASSIGN)
		tmp = g_operators[root->right->type -
						OPSHIFT](ft_atoi(sgetenv(var, ENV_ALL)), root->right);
	else
		tmp = calc(root->right->left);
	val = ft_itoa(tmp);
	ssetenv(root->left->content, val, ENV_RO);
	free(val);
	return (tmp);
}

intmax_t	get_var_value(t_astree *root)
{
	char	*var;
	char	*val;

	if (!(var = get_pre_incdec(root)))
		return (0);
	if (!(val = sgetenv(var, ENV_ALL)))
		return (0);
	return (ft_atoi(val));
}

intmax_t	calc(t_astree *root)
{
	if (!root)
		return (0);
	if (root->type == EX_NUM)
		return (ft_atoi(root->content));
	if (root->type == EX_VAR)
		return (get_post_incdec(root));
	if (root->type == EX_INC || root->type == EX_DEC)
		return (get_var_value(root));
	if (root->type == EX_QUES)
		return (get_ques(root));
	if (root->type == EX_ASSIGN)
		return (get_assign(root));
	if (root->type == EX_ADD || root->type == EX_SUB ||
		root->type == EX_LNOT || root->type == EX_BNOT)
		return (applay_unary(root));
	if (root->type == EX_EXPR)
		return (g_operators[root->right->type -
						OPSHIFT](calc(root->left), root->right));
		return (0);
}
