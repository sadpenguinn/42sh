/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:02:38 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/20 14:39:56 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int		function(t_astree *func, char **argv, int fd[2], int job)
{
	int		res;

	(void)argv;
	res = execlist1(func, fd, job);
	(void)argv;
	return (res);
}
