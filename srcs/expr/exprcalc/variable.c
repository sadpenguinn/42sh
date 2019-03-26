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

static char	*recursivevar(char *var)
{
	char	*val;

	if (!(val = sgetenv(var, ENV_ALL)))
		return (var);
	if (ft_str_is_number(val))
		return (var);
	if (val && !check_varname(val))
	{
		g_exprerr = 1;
		ft_putstr_fd("42sh: bad variable value:", STDERR_FILENO);
		ft_putstr_fd(val, STDERR_FILENO);
		return ((char *)0);
	}
	return (recursivevar(val));
}

intmax_t	get_post_incdec(t_astree *root)
{
	intmax_t	tmp;
	char		*val;
	char		*var;

	var = recursivevar(root->content);
	val = sgetenv(var, ENV_ALL);
	tmp = (val) ? ft_atoi(val) : 0;
	if (!(root->left))
		return (tmp);
	if (root->left->type == EX_INC)
		val = ft_itoa(tmp + 1);
	else
		val = ft_itoa(tmp - 1);
	ssetenv(root->content, val, ENV_RO);
	free(val);
	return (tmp);
}

char		*get_pre_incdec(t_astree *root)
{
	char		*val;
	char		*var;

	if (root->type == EX_VAR)
	{
		val = sgetenv(recursivevar(root->content), ENV_ALL);
		ssetenv(root->content, (val ? val : "0"), ENV_RO);
		return (root->content);
	}
	if (!(var = get_pre_incdec(root->left)))
		return ((char *)0);
	if (root->type == EX_INC)
		val = ft_itoa(ft_atoi(sgetenv(var, ENV_ALL)) + 1);
	else
		val = ft_itoa(ft_atoi(sgetenv(var, ENV_ALL)) - 1);
	ssetenv(var, val, ENV_RO);
	free(val);
	return (var);
}
