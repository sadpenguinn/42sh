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

# define BUILTT_FC_TMP_FILE ".fc_tmp_file"

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
** Builtin 'echo' parses flags and prints strings.
** The following flags are supported: -n, -e, -E.
** -n -- print string without '\n' at the end.
** -e -- interpret sequences.
** -E -- don't interpret sequences.
*/

int		built_echo(char **av, char **env);

/*
** Exit, returning a status of n to the shell’s parent
** exit [n]
*/

int		built_exit(char **av, char **env);

/*
** Mark each name to be passed to child processes in the environment
** -n - delete variables
** -p - like an export without flags, prints list of variables
** export [-n] [-p] [name[=value]]
*/

int		built_export(char **av, char **env);

/*
** hash [-r] [-p filename] [-dt]
*/

int		built_hash(char **av, char **env);

/*
** Alias builtin
** alias [-p] [name[=value] ...]
**  -p flag means - print list of all aliases
*/

int		built_alias(char **av, char **env);

/*
** unalias [-a] [name … ]
** -a removes all variables
*/

int		built_unalias(char **av, char **env);

/*
** type [-afptP] [name …]
*/

int		built_type(char **av, char **env);

/*
** Evaluate a conditional expression expr
** and return a status of 0 (true) or 1 (false)
** test expr
*/

int		built_test(char **av, char **env);

/*
** Standard builtin 'set' with flags '-n' and '-o'
** for modifying shell behavior
*/

int		built_set(char **av, char **env);

/*
** Remove each variable or function name
** unset [-fnv] [name]
** If the -v option is given, each name refers to a shell variable and that variable is removed
** If the -f option is given, each name refers to a shell function and that function is removed
** If the -n option is given, each name refers to a shell variable and that variable value is removed
*/

int		built_unset(char **av, char **env);

/*
** Just prints environment
*/

int		built_env(char **av, char **env);

/*
** Adds variable to the environment.
** Following syntax are supported:
** setenv [name value]
*/

int		built_setenv(char **av, char **env);

/*
** Removes variable from the environment.
** unsetenv [name]
*/

int		built_unsetenv(char **av, char **env);

/*
** Internal functions for echo
*/

int		echo_handle_sequence(const char *str, int i);
int		echo_switch(char **av, int i, int *flags);
int		echo_usage(char c);

/*
** Internal functions for hash
*/

void	hash_print_bin(char *key, char *value);
void	built_hash_parg(char **av);
void	built_hash_darg(char **av);
void	built_hash_targ(char **av);
void	built_hash_larg(char **av);

/*
** Internal functions for alias
*/

int			alias_print_error(char *arg);
void		alias_print_alias(char *key);
int			alias_parse_assignments(char **av);
int			alias_print_aliases(void);

/*
** Internal functions for set
*/

int		built_set_usage(void);
int		built_set_toggle(int *var, int fval, int sval);
int		built_set_gvar(int *var, int val);
void	built_set_print(void);

// The following source files should be added comments

/*
** jobs [jobspec]
*/

int		built_jobs(char **av, char **env);

/*
** Resume job jobspec in the background
** bg  [jobspec ]
*/

int		built_bg(char **av, char **env);

/*
** Resume the job jobspec in the foreground and make it the current job
** fg [jobspec]
*/

int		built_fg(char **av, char **env);

/*
** fc [-e ename] [-lnr] [first] [last]
** fc -s [pat=rep] [command]
*/

int		built_fc(char **av, char **env);

/*
** Internal functions for fc
*/

int		built_fc_case_default(char **av, int i, int *flags, void *fc_history);
int		built_fc_case_e(char **av, int i, int *flags, void *fc_history);
int		built_fc_case_l(char **av, int i, int *flags, void *fc_history);
int		built_fc_case_s(char **av, int i, int *flags, void *fc_history);
int		built_fc_usage(int error);
void	built_fc_swap_limits(size_t *left_limit, size_t *right_limit);
void	built_fc_set_limits_default(size_t *left_limit, size_t *right_limit,
									void *fc_history, const int *flags);
int		built_fc_write_lines(void *fc_history, int fd, int *flags, char **av);
int		built_fc_parse_string(char *script, int print);
int		built_fc_open_tmp_file(char **file_name);
void	built_fc_write_history_changes(void);

#endif
