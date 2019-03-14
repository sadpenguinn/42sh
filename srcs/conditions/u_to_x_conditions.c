/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_to_x_conditions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:47:53 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/14 17:52:41 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conditions.h"

int		u_conditions(char *str)
{
	struct stat	*buff;
	int			res;

	buff = xmalloc(sizeof(struct stat));
	res = 0;
	if (stat(str, buff) == -1)
		return (0);
	if (buff->st_mode & S_ISUID)
		res = 1;
	else
		res = 0;
	free(buff);
	return (res);
}

int		w_conditions(char *str)
{
	struct stat	*buff;
	int			res;

	buff = xmalloc(sizeof(struct stat));
	res = 0;
	if (stat(str, buff) == -1)
		return (0);
	if (buff->st_mode & S_IWUSR)
		res = 1;
	else
		res = 0;
	free(buff);
	return (res);
}

int		x_conditions(char *str)
{
	struct stat	*buff;
	int			res;

	buff = xmalloc(sizeof(struct stat));
	res = 0;
	if (stat(str, buff) == -1)
		return (0);
	if (buff->st_mode & S_IXUSR)
		res = 1;
	else
		res = 0;
	free(buff);
	return (res);
}
