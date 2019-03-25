/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:39:09 by bwerewol          #+#    #+#             */
/*   Updated: 2019/03/02 19:09:56 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <unistd.h>
# include "libhash.h"
# include "libalias.h"
# include "../srcs/lib/libshell/includes/libshell.h"
# include "vector.h"

/*
** Checking platform defines
*/

# if defined(__APPLE__) || defined(__MACH__)
#  define STATS_TIME_SEC stats.st_mtimespec.tv_sec
# elif defined(__linux__)
#  define STATS_TIME_SEC stats.st_mtim.tv_sec
# else
#  define STATS_TIME_SEC stats.st_mtimespec.tv_sec
# endif

/*
** Struct for parser which implement abstract syntax tree
*/

typedef struct			s_astree
{
	int				type;
	char			*content;
	struct s_astree	*left;
	struct s_astree	*right;
}						t_astree;

/*
** Struct for jobs
*/

typedef struct			s_job
{
	int		state;
	int		status;
	void	*pids;
	void	*sub_pids;
}						t_job;

/*
** Global variables with env, aliases and paths hashes/arrays.
** 'roenv' arrays stores only read-only variables
*/

extern t_hash			*g_hash_env;
extern t_hash			*g_hash_roenv;
extern t_hash			*g_path;
extern t_hash			*g_path_sums;
extern t_alias			*g_aliases;
extern t_env			g_env;
extern t_env			g_roenv;

/*
** Global variables for saving jobs and pids
** of running processes to kill them
*/

extern void				*g_jobs;
extern void				*g_pids;

/*
** Vectors which stores functions trees and them arguments
*/

extern void				*g_func;
extern void				*g_func_args;

/*
** Global variables with status of previous operation - $?
*/

extern int				g_status;

/*
** Defines for 'set' builtin witch modify the shell behavior
*/

extern int				g_echoe;
extern int				g_dontexec;

/*
**	Copy stdin descriptors
*/

extern int				g_stdin_fd;

/*
** Default path to 42 shell
*/

# define SHELL_DEFAULT_PATH "/bin/42sh"
# define SHELL_DEFAULT_HOME "/"
# define SHELL_DEFAULT_LAST "0"
# define SHELL_DEFAULT_RC "/.42shrc"

/*
** Bool defines, used in builtins
*/

# define TRUE 1
# define FALSE 0

/*
** Defines for initialize shell environment/path/aliases
*/

# define INITIAL_ENV_HASH_SIZE			100
# define INITIAL_PATH_HASH_SIZE			20
# define INITIAL_PATH_SUMS_HASH_SIZE	20
# define INITIAL_ALIASES_SIZE			100
# define GENV_REALLOC					50

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

/*
** Defines for --help and --version flags
*/

# define SHELL_VERSION "42sh, version 0.1\n"
# define SHELL_AUTHORS "Authors:\nnkertzma, bwerewol, narchiba, bbaelor-\n"
# define SHELL_USAGE "Usage:\t\t42sh [option] [file]\n"
# define SHELL_OPT "Options:\n"
# define SHELL_OPT_C "-c\t\tWith -c options, commands are read from string\n"
# define SHELL_OPT_H "-h\t\tPrint help\n"
# define SHELL_OPT_V "-v\t\tPrint version\n"
# define SHELL_LOPT "Long options:\n"
# define SHELL_LOPT_H "--help\t\tThe same as -h\n"
# define SHELL_LOPT_V "--version\tThe same as -v\n"

/*
** Defines for shell parser
*/

t_astree				*inputunit(void);
void					print_astree(t_astree *root);

/*
** Initialize and destroy shell, also prototypes for parsing
** input and arguments, prototype for init signal handler
*/

void					init(char **env, char **av);
void					init_env(char **env, char **av);
void					init_path(void);
void					init_jobs(void);
void					init_process(void);
void					init_functions(void);
void					init_function_args(void);
void					init_aliases(void);
void					destroy(void);
void					destroy_env(void);
void					destroy_path(void);
void					destroy_jobs(void);
void					destroy_process(void);
void					destroy_pids(void);
void					destroy_aliases(void);
void					destroy_functions(void);
void					destroy_function_args(void);
void					init_signals(void);
void					parse_config(void);
int						parse_input(int ac, char **av);
int						argv_parser(int ac, char **av);

/*
**	Execute command and return descriptor
**	If parser or execute error returns -1
*/

int						substitution(char *cmd, int isoutput);
char					*subtitution_output(char *cmd);

/*
**	Jobs
*/

int						addjob(int state, pid_t pid);

# define JOB_RUN		1
# define JOB_STOP		2

#endif
