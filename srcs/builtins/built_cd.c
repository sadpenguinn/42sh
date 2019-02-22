/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:15:08 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/22 20:08:55 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static char		*get_oldpwd(char *def)
{
	char	*oldpwd;

	oldpwd = sgetenv("OLDPWD");
	return (oldpwd ? oldpwd : def);
}

static void		set_pwd(const char *str)
{
	char	*buf;
	size_t	size;

	size = 100;
	buf = (char *)xmalloc(sizeof(char) * size);
	if (getcwd(buf, size))
		ssetenv(str, buf);
	else
		ssetenv(str, "/");
	ft_strdel(&buf);
}

/*
** Builtin 'cd' that supports working with 'OLDPWD' / 'PWD' variables.
** It also supports moving to the previous directory with '-' flag, but without
** handling stack like '-3', '-10', etc.
*/

int				built_cd(char **av, char **env)
{
	char	*path;
	char	*home;

	env = NULL;
	if (!(home = sgetenv("HOME")))
		home = "/";
	if (!av[1])
		path = ft_strdup(home);
	else if (!ft_strcmp(av[1], "-"))
		path = ft_strdup(get_oldpwd(home));
	else
		path = ft_strdup(av[1]);
	set_pwd("OLDPWD");
	if (!chdir(path))
	{
		ft_strdel(&path);
		set_pwd("PWD");
		return (SHERR_OK);
	}
	sputerr(sstrerr(SHERR_ENOENT));
	return (SHERR_ERR);
}
