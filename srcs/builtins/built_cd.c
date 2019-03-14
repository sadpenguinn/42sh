/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:15:08 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/28 18:37:27 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pwd.h>
#include "shell.h"
#include "builtins.h"

static int		cd_parse_flags(char **av, int *flags)
{
	int		i;

	i = 1;
	ft_memset(flags, '\0', sizeof(int) * 4);
	while (av[i])
	{
		if (!ft_strcmp(av[i], "-L"))
			flags[0] = 1;
		else if (!ft_strcmp(av[i], "-P"))
			flags[1] = 1;
		else if (!ft_strcmp(av[i], "-e"))
			flags[2] = 1;
		else if (!ft_strcmp(av[i], "-@"))
			flags[3] = 1;
		else
			return (i);
		i++;
	}
	return (i);
}

static char		*cd_get_oldpwd(char *def)
{
	char	*oldpwd;

	oldpwd = sgetenv("OLDPWD", ENV_ALL);
	return (oldpwd ? oldpwd : def);
}

static void		cd_set_pwd(const char *str)
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

static char		*cd_get_home(void)
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

static char		*cd_get_path(char **av, int i, char *home)
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

static int		cd_try_chdir(char *path)
{
	if (!chdir(path))
	{
		cd_set_pwd("PWD");
		return (1);
	}
	return (0);
}

static int		cd_iterate_cdpath(char **av, int i)
{
	char	**paths;
	char	*cdpath;
	char	*path;
	int		k;

	k = 0;
	if (!(cdpath = sgetenv("CDPATH", ENV_ALL)))
		return (0);
	paths = ft_strsplit(cdpath, ':');
	while (paths[k])
	{
		path = ft_strjoin(paths[k], "/", 0);
		path = ft_strjoin(path, av[i], 1);
		if (cd_try_chdir(path))
		{
			free_str_arr(&paths);
			ft_strdel(&path);
			return (1);
		}
		ft_strdel(&path);
		k++;
	}
	free_str_arr(&paths);
	return (0);
}

/*
** Builtin 'cd' that supports working with 'OLDPWD' / 'PWD' / 'CDPATH' variables.
** It also supports moving to the previous directory with '-' flag, but without
** handling stack like '-3', '-10', etc.
*/

int				built_cd(char **av, char **env)
{
	int		flags[4];
	char	*home;
	char	*path;
	int		i;

	env = NULL;
	i = cd_parse_flags(av, flags);
	home = cd_get_home();
	path = cd_get_path(av, i, home);
	cd_set_pwd("OLDPWD");
	if (!(cd_iterate_cdpath(av, i)))
	{
		if (!(cd_try_chdir(path)))
		{
			sputcmderr(sstrerr(SHERR_ENOENT), "cd", path);
			ft_strdel(&path);
			return (SHERR_ERR);
		}
		else
		{
			ft_strdel(&path);
			return (SHERR_OK);
		}
	}
	return (SHERR_OK);
}
