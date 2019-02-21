/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:15:08 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/21 11:02:06 by nkertzma         ###   ########.fr       */
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

	buf = NULL;
	if (getcwd(buf, 0))
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
	if (!(path = av[1]))
		path = home;
	if (!ft_strcmp(av[1], "-"))
		path = get_oldpwd(home);
	set_pwd("OLDPWD");
	if (!chdir(path))
	{
		set_pwd("PWD");
		return (SHERR_OK);
	}
	sputerr(sstrerr(SHERR_ENOENT));
	return (SHERR_ERR);
}
