/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_cd_reqmts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:09:33 by nkertzma          #+#    #+#             */
/*   Updated: 2019/03/25 14:09:34 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pwd.h>
#include "builtins.h"
#include "shell.h"

char		*cd_get_oldpwd(char *def)
{
	char	*oldpwd;

	oldpwd = sgetenv("OLDPWD", ENV_ALL);
	return (oldpwd ? oldpwd : def);
}

void		cd_set_pwd(const char *str)
{
	char	*buf;
	size_t	size;

	size = 100;
	buf = (char *)xmalloc(sizeof(char) * size);
	if (getcwd(buf, size))
		ssetenv(str, buf, ENV_EXP);
	else
		ssetenv(str, "/", ENV_EXP);
	ft_strdel(&buf);
}

char		*cd_get_home(void)
{
	struct passwd	*passwd;
	uid_t			uid;
	char			*home;

	if (!(home = sgetenv("HOME", ENV_ALL)))
	{
		uid = getuid();
		if (!(passwd = getpwuid(uid)))
			return (SHELL_DEFAULT_HOME);
		return (passwd->pw_dir);
	}
	return (home);
}

char		*cd_get_path(char **av, int i, char *home)
{
	char	*path;

	if (!av[i])
		path = ft_strdup(home);
	else if (!ft_strcmp(av[i], "-"))
		path = ft_strdup(cd_get_oldpwd(home));
	else
		path = ft_strdup(av[i]);
	return (path);
}
