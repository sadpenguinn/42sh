/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 11:46:37 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/24 11:46:37 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int		execute(t_astree *root)
{
	int fd[2];
	int res;

	fd[0] = STDIN_FILENO;
	fd[1] = STDOUT_FILENO;
	res = execlist1(root, fd, 0, 0);
	return (res);
}
