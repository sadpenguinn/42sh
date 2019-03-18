/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:13:40 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/26 17:32:22 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <stdlib.h>
# include <unistd.h>
# include "libshell.h"
# include "libalias.h"

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
# endif

# ifndef FC_ERROR
#  define FC_ERROR
#  define FC_ERROR_EVENT 1
#  define FC_ERROR_ARGS 2
#  define FC_ERROR_FLAGS 3
# endif

/*
** Builtin 'cd' that supports working with 'OLDPWD' / 'PWD' / 'CDPATH' variables.
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
*/

int		built_exit(char **av, char **env);

/*
** Standard builtin 'set' with flags '-n' and '-o'
** for modifying shell behavior
*/

int		built_set(char **av, char **env);

int		built_hash(char **av, char **env);

int		built_export(char **av, char **env);

int		built_jobs(char **av, char **env);

int		built_bg(char **av, char **env);

int		built_fg(char **av, char **env);

int		built_alias(char **av, char **env);

int		built_unalias(char **av, char **env);

int		built_type(char **av, char **env);

int		built_test(char **av, char **env);

int		built_fc(char **av, char **env);

/*
** Internal function for fc
*/

int		built_fc_case_default(char **av, int i, int *flags, void **fc_history);
int		built_fc_case_e(char **av, int i, int *flags, void **fc_history);
int		built_fc_case_l(char **av, int i, int *flags, void **fc_history);
int		built_fc_case_s(char **av, int i, int *flags, void **fc_history);
int		built_fc_usage(int error);
void	built_fc_swap_limits(size_t *left_limit, size_t *right_limit);
void	built_fc_set_limits_default(size_t *left_limit, size_t *right_limit, void *fc_history);
void	write_lines(void **fc_history, int fd, int *flags, char **av);

/*
** Internal function for echo
*/

int		echo_handle_sequence(const char *str, int i);
int		echo_switch(char **av, int i, int *flags);
int		echo_usage(char c);

/*
** Internal function for hash
*/

void	print_bin(char *key, char *value);
void	built_hash_parg(char **av);
void	built_hash_darg(char **av);
void	built_hash_targ(char **av);
void	built_hash_larg(char **av);

/*
** Internal function for set
*/

int		built_set_usage(void);
int		built_set_toggle(int *var, int fval, int sval);
int		built_set_gvar(int *var, int val);
void	built_set_print(void);

#endif
