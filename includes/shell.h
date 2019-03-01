/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:39:09 by bwerewol          #+#    #+#             */
/*   Updated: 2019/03/01 17:01:23 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <unistd.h>
# include <sys/stat.h>
# include <signal.h>
# include "libshell.h"
# include "libhash.h"
# include "vector.h"
# include "readline.h"
# include "lexer.h"

/*
** Global variables with env and paths hashes/arrays
*/

extern t_hash			*g_hash_env;
extern t_hash			*g_path;
extern t_hash			*g_path_sums;
extern struct s_env		g_env;

/*
** Global variables for saving jobs and processes
*/

extern void				*g_jobs;
extern void				*g_process;
extern void				*g_pids;

/*
** Defines for initialize shell environment/path
*/

# define INITIAL_ENV_HASH_SIZE			100
# define INITIAL_PATH_HASH_SIZE			20
# define INITIAL_PATH_SUMS_HASH_SIZE	20
# define GENV_REALLOC					50

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

typedef struct			s_env
{
	char				**env;
	size_t				size;
	size_t				filled;
}						t_env;

/*
** Struct for parser
*/

typedef struct			s_astree
{
	int				type;
	char			*content;
	struct s_astree	*left;
	struct s_astree	*right;
}						t_astree;

t_astree				*inputunit(void);
void					print_astree(t_astree *root);

/*
** Initialize and destroy shell
*/

void					init(char **env);
void					init_env(char **env);
void					init_path(void);
void					init_jobs(void);
void					init_process(void);
void					init_pids(void);
void					destroy(void);
void					destroy_env(void);
void					destroy_path(void);
void					destroy_jobs(void);
void					destroy_process(void);
void					destroy_pids(void);
void					init_signals(void);
int						parse_input(int ac, char **av);
int						argv_parser(int ac, char **av);

/*
** Minishell requirements
*/

extern int				g_pid;

void					minishell_parser(void *lexems);
char					*ft_strvardup(char *str);

#endif
