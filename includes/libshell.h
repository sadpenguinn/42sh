/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libshell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 19:34:24 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/28 14:30:02 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSHELL_H
# define LIBSHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <dirent.h>
# include <fcntl.h>
# include "libft.h"
# include "libhash.h"

/*
** Defines for sgetpath and get_cmd_path.
** PATH_NULL means there is no command, PATH_BUILT - builtin
** was found, PATH_BIN - binary was found at hash table and PATH_EXIT -
** exit builtin
*/

# define PATH_NULL 0
# define PATH_BUILT 1
# define PATH_BIN 2
# define PATH_EXIT 3

/*
** Shell error define like a standard C errno
*/

# ifndef SHERR
#  define SHERR
#  define SHERR_ERR						0
#  define SHERR_OK						1
#  define SHERR_ENOENT					2
#  define SHERR_CNTFRK					3
#  define SHERR_CMNDNTF					4
#  define SHERR_INVSNTX					5
#  define SHERR_CNTALCTMEM				6
# endif

/*
** Variable names verification
*/

int		check_varname(char *var);
char	*check_valid_of_variable(char *str);

/*
** Implementation of UNIX standard functions glob and match
*/

int		xglob(char *pattern, char *path, char ***matches, size_t *cnt);
int		xmatch(char *s1, char *s2);

/*
** Functions for prints errors.
** Defines for those declared in shell.h
*/

void	die(void);
void	sputerr(char *err);
void	sputcmderr(char *err, char *cmd, char *arg);
char	*sstrerr(int e);

/*
** Functions for working with hash tables that represents
** environment and binaries
*/

char	*sgetenv(const char *key);
int		ssetenv(const char *key, const char *value);
int		sunsetenv(const char *key);
int		sgetpath(const char *bin, void **ret);
int		get_cmd_path(char *str, void **ret);

/*
** Other functions for working with two-dimensional arrays
*/
void	free_str_arr(char ***arr);
void	print_str_arr(char *const *arr);
char	**split_env(char *str);

#endif
