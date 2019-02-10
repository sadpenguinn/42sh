/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 20:02:37 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/10 21:57:55 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_astree	*get_shell_command(void)
{
	t_astree	*res[2];
	t_astree	*root;
printf("in get shell cmd\n");
	if (!(res[0] = shell_command()))
		return (0);
	if (!(res[1] = redirection_list()))
		return (res[0]);
	root = xmalloc(sizeof(t_astree));
	root->type = CMDREDIR;
	root->left = res[0];
	root->right = res[1];
	return (root);
}

t_astree	*command(void)
{
	t_astree        *res;

	if ((res = function_def()))
		return (res);
	else if ((res = get_shell_command()))
		return (res);
	else if ((res = simple_command()))
		return (res);
	return (0);
}
