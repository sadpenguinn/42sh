/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_to_s_conditions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:47:14 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/14 17:53:02 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conditions.h"

int		bl_conditions(char *str)
{
	struct stat	*buff;
	int			res;

	buff = xmalloc(sizeof(struct stat));
	res = 0;
	if (stat(str, buff) == -1)
		return (0);
	if (S_ISLNK(buff->st_mode))
		res = 1;
	else
		res = 0;
	free(buff);
	return (res);
}

int		p_conditions(char *str)
{
	struct stat	*buff;
	int			res;

	buff = xmalloc(sizeof(struct stat));
	res = 0;
	if (stat(str, buff) == -1)
		return (0);
	if (S_ISFIFO(buff->st_mode))
		res = 1;
	else
		res = 0;
	free(buff);
	return (res);
}

int		r_conditions(char *str)
{
	struct stat	*buff;
	int			res;

	buff = xmalloc(sizeof(struct stat));
	res = 0;
	if (stat(str, buff) == -1)
		return (0);
	if (buff->st_mode & S_IRUSR)
		res = 1;
	else
		res = 0;
	free(buff);
	return (res);
}

int		bs_conditions(char *str)
{
	struct stat	*buff;
	int			res;

	buff = xmalloc(sizeof(struct stat));
	res = 0;
	if (stat(str, buff) == -1)
		return (0);
	if (S_ISSOCK(buff->st_mode))
		res = 1;
	else
		res = 0;
	free(buff);
	return (res);
}

int		s_conditions(char *str)
{
	struct stat	*buff;
	int			res;

	buff = xmalloc(sizeof(struct stat));
	res = 0;
	if (stat(str, buff) == -1)
		return (0);
	if (buff->st_size > 0)
		res = 1;
	else
		res = 0;
	free(buff);
	return (res);
}
