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

#include "execute.h"

int		function(t_astree *func, char **argv, char **envp)
{
	int		fd[2];
	char	*arg;

	(void)envp;
	fd[0] = 0;
	fd[1] = 1;
	while (*argv)
	{
		arg = ft_strdup(*argv++);
		vector_push_back(&g_func_args, arg);
	}
	return (execlist1(func, fd, 0));
}
