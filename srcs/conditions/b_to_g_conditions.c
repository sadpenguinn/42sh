/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_g_conditions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:46:11 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/14 17:52:36 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conditions.h"

int		b_conditions(char *str)
{
	struct stat	*buff;
	int			res;

	buff = xmalloc(sizeof(struct stat));
	res = 0;
	if (stat(str, buff) == -1)
		return (0);
	if (S_ISBLK(buff->st_mode))
		res = 1;
	else
		res = 0;
	free(buff);
	return (res);
}

int		c_conditions(char *str)
{
	struct stat	*buff;
	int			res;

	buff = xmalloc(sizeof(struct stat));
	res = 0;
	if (stat(str, buff) == -1)
		return (0);
	if (S_ISCHR(buff->st_mode))
		res = 1;
	else
		res = 0;
	free(buff);
	return (res);
}

int		e_conditions(char *str)
{
	if (access(str, F_OK) != -1)
		return (1);
	return (0);
}

int		f_conditions(char *str)
{
	struct stat	*buff;
	int			res;

	buff = xmalloc(sizeof(struct stat));
	res = 0;
	if (stat(str, buff) == -1)
		return (0);
	if (S_ISREG(buff->st_mode))
		res = 1;
	else
		res = 0;
	free(buff);
	return (res);
}

int		g_conditions(char *str)
{
	struct stat	*buff;
	int			res;

	buff = xmalloc(sizeof(struct stat));
	res = 0;
	if (stat(str, buff) == -1)
		return (0);
	if (buff->st_mode & S_ISGID)
		res = 1;
	else
		res = 0;
	free(buff);
	return (res);
}
