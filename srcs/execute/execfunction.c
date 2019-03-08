/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:02:38 by bwerewol          #+#    #+#             */
/*   Updated: 2019/03/04 18:52:44 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	FN - FunctioN
**	FNBD - FunctioN BoDy
**
** FN(content:WORD)
**   \
**    FNBD
*/

#include "execute.h"
#include "parser.h"

int		execfunction(t_astree *root)
{
	t_func	*function;
	size_t	size;
	size_t	i;
	t_func	func;

	i = 0;
	size = vector_get_len(g_func);
	while (i < size)
	{
		function = (t_func *)vector_get_elem(g_func, i);
		if (!ft_strcmp(function->name, root->content))
		{
			freeastree(function->func);
			function->func = root->right;
			root->right = 0;
			return (EXIT_SUCCESS);
		}
		i++;
	}
	func.name = ft_strdup(root->content);
	func.func = root->right;
	root->right = 0;
	vector_push_back(&g_func, &func);
	return (EXIT_SUCCESS);
}
