/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:39:09 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/22 21:16:07 by nkertzma         ###   ########.fr       */
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
extern char				**g_env;

/*
** Global variables for saving jobs and processes
*/

extern void				*g_jobs;
extern void				*g_process;

/*
** Defines for initialize shell environment/path
*/

# define INITIAL_ENV_HASH_SIZE			100
# define INITIAL_PATH_HASH_SIZE			20
# define INITIAL_PATH_SUMS_HASH_SIZE	20

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

/*
** Defines for --help and --version flags
*/

# define SHELL_VERSION "42sh, version 0.1"
# define SHELL_AUTHORS "Authors:\nnkertzma, bwerewol, narchiba, bbaelor-"
# define SHELL_USAGE "Usage:\t\t42sh [option] [file]"
# define SHELL_OPTIONS "Options:\n-c\t\tWith -c options, commands are read from string\n-h\t\tPrint help\n-v\t\tPrint version\nLong options:\n--help\t\tThe same as -h\n--version\tThe same as -v"

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
void					destroy(void);
void					destroy_env(void);
void					destroy_path(void);
void					destroy_jobs(void);
void					destroy_process(void);
void					init_signals(void);
int						argv_parser(int ac, char **av);

/*
** Minishell requirements
*/

extern int				g_pid;

void					minishell_parser(void *lexems);
char					*ft_strvardup(char *str);

#endif
