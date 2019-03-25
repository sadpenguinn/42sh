/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libshell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 19:34:24 by nkertzma          #+#    #+#             */
/*   Updated: 2019/03/20 12:54:55 by bbaelor-         ###   ########.fr       */
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

typedef struct	s_env
{
	char		**env;
	size_t		size;
	size_t		filled;
}				t_env;

# define ENV_EXP 1
# define ENV_RO 2
# define ENV_ALL 3

/*
** Defines for sgetpath and get_cmd_path.
** PATH_NULL means there is no command, PATH_BUILT - builtin
** was found, PATH_BIN - binary was found at hash table and PATH_EXIT -
** exit builtin
*/

# define PATH_NULL 0
# define PATH_BUILT 1
# define PATH_BIN 2
# define PATH_NOFORK 3
# define PATH_FUNC 4

/*
** Shell error define like a standard C errno
*/

# ifndef SHERR
#  define SHERR
#  define SHERR_OK						0
#  define SHERR_ERR						1
#  define SHERR_ENOENT					2
#  define SHERR_CNTFRK					3
#  define SHERR_CMNDNTF					4
#  define SHERR_INVSNTX					5
#  define SHERR_CNTALCTMEM				6
#  define SHERR_PERMDEN					7
#  define SHERR_NSE						8
#  define SHERR_CNTOPF					9
# endif

# ifndef C_COLORS
#  define C_COLORS
#  define C_DEFAULT "\x1b[0m"
#  define C_BOLD "\x1b[1m"
#  define C_LIGHT "\x1b[2m"
#  define C_RM_LIGHT "\x1b[22m"
#  define C_UNDERLINE "\x1b[4m"
#  define C_RM_UNDERLINE "\x1b[24m"
#  define C_BLINK "\x1b[5m"
#  define C_RM_BLINK "\x1b[25m"

#  define C_BLACK "\x1b[30m"
#  define C_RED "\x1b[31m"
#  define C_GREEN "\x1b[32m"
#  define C_YELLOW "\x1b[33m"
#  define C_BLUE "\x1b[34m"
#  define C_PURPLE "\x1b[35m"
#  define C_AQUA "\x1b[36m"
#  define C_GRAY "\x1b[37m"

#  define BG_BLACK "\x1b[40m"
#  define BG_RED "\x1b[41m"
#  define BG_GREEN "\x1b[42m"
#  define BG_YELLOW "\x1b[43m"
#  define BG_BLUE "\x1b[44m"
#  define BG_PURPLE "\x1b[45m"
#  define BG_AQUA "\x1b[46m"
#  define BG_GRAY "\x1b[47m"
# endif

/*
** Implementation of UNIX standard functions glob and match
*/

int				xglob(char *pattern, char *path, char ***matches, size_t *cnt);
void			glob_free(char ***matches, size_t i);
int				xmatch(char *s1, char *s2);

/*
** Functions for prints errors.
** Defines for those declared in shell.h
*/

void			die(void);
void			sputerr(char *err);
void			sputcmderr(char *err, char *cmd, char *arg);
char			*sstrerr(int e);

/*
** Functions for working with hash tables that represents
** environment and binaries
*/

char			*sgetenv(const char *key, int local);
int				ssetenv(const char *key, const char *value, int local);
int				sunsetenv(const char *key, int local);
int				sgetpath(const char *bin, void **ret);
int				get_cmd_path(char *str, void **ret);
void			fill_genv(t_env *env, t_hash *hash_env);

/*
** Other functions for working with two-dimensional arrays
*/

void			free_str_arr(char ***arr);
void			print_str_arr(char *const *arr);
size_t			size_str_arr(char *const *arr);
char			**split_assignments(char *str);

size_t			get_file_size(const char *file);

int				check_varname(const char *str);

#endif
