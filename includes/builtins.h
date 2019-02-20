/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:13:40 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/20 15:43:43 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <unistd.h>
# include <stdlib.h>

/*
** Shell error define like a standard C errno
*/
# ifndef SHERR
#  define SHERR
#  define SHERR_ERR 0
#  define SHERR_OK 1
#  define SHERR_ENOENT 2
# endif

/*
** Builtin 'cd' that supports working with 'OLDPWD' / 'PWD' variables.
** It also supports moving to the previous directory with '-' flag, but without
** handling stack like '-3', '-10', etc.
*/

int		built_cd(char **av, char **env);

/*
** Builtin 'echo' parses flags and print strings.
** The following flags are supported: -n, -e, -E.
** -n -- print string without '\n' at the end.
** -e -- interpret sequences.
** -E -- don't interpret sequences.
*/

int		built_echo(char **av, char **env);

/*
** Just prints environment. If passed arguments, env display an error
*/

int		built_env(char **av, char **env);

/*
** Adds variable to the environment.
** Following syntax are supported:
** setenv USER pahom
*/

int		built_setenv(char **av, char **env);

/*
** Removes variable from the environment.
** Following syntax are supported:
** unsetenv USER
*/

int		built_unsetenv(char **av, char **env);

/*
** Exit
** Need to add handling of running processes
*/

int		built_exit(char **av, char **env);

#endif
