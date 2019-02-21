/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:39:09 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/21 10:55:31 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <unistd.h>
# include <sys/stat.h>
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
# endif

/*
** Defines for lexer/parser
*/

# define TERM_SHIFT              		50
# define TERM_DO                		TERM_SHIFT + 3 /* do */
# define TERM_DONE              		TERM_SHIFT + 5 /* done */
# define TERM_CASE              		TERM_SHIFT + 9 /* case */
# define TERM_ELIF              		TERM_SHIFT + 13 /* elif */
# define TERM_ELSE              		TERM_SHIFT + 15 /* else */
# define TERM_ESAC              		TERM_SHIFT + 18 /* esac */
# define TERM_FUNCTION          		TERM_SHIFT + 26 /* function */
# define TERM_FOR               		TERM_SHIFT + 28 /* for */
# define TERM_SELECT            		TERM_SHIFT + 31 /* select */
# define TERM_FI                		TERM_SHIFT + 32 /* fi */
# define TERM_IN                		TERM_SHIFT + 34 /* in */
# define TERM_IF                		TERM_SHIFT + 36 /* if */
# define TERM_THEN              		TERM_SHIFT + 40 /* then */
# define TERM_UNTIL             		TERM_SHIFT + 45 /* until */
# define TERM_WHILE             		TERM_SHIFT + 52 /* while */
# define TERM_WORD              		TERM_SHIFT + 53 /* word */
# define TERM_NEWLINE           		TERM_SHIFT + 54 /* \n */
# define TERM_SPACE             		TERM_SHIFT + 56 /* sp */
# define TERM_TAB             			TERM_SHIFT + 56 /* tab */
# define TERM_LESS              		TERM_SHIFT + 57 /* < */
# define TERM_GREAT             		TERM_SHIFT + 58 /* > */
# define TERM_COMMENT           		TERM_SHIFT + 60 /* comment */
# define TERM_DLESS             		TERM_SHIFT + 61 /* << */
# define TERM_DGREAT            		TERM_SHIFT + 62 /* >> */
# define TERM_DLESSDASH         		TERM_SHIFT + 64 /* <<- */
# define TERM_CLOBBER           		TERM_SHIFT + 65 /* >| */
# define TERM_LESSGREAT         		TERM_SHIFT + 71 /* <> */

# define TERM_AND_IF            		TERM_SHIFT + 221 /* && */
# define TERM_OR_IF             		TERM_SHIFT + 222 /* || */
# define TERM_LESSAND           		TERM_SHIFT + 226 /* <& */
# define TERM_GREATAND          		TERM_SHIFT + 227 /* &> */
# define TERM_LBRACE            		TERM_SHIFT + 212 /* { */
# define TERM_RBRACE            		TERM_SHIFT + 213 /* } */
# define TERM_DBL_LBRACKET      		TERM_SHIFT + 214 /* [[ */
# define TERM_DBL_RBRACKET      		TERM_SHIFT + 215 /* ]] */
# define TERM_DBL_LPARENTHESIS  		TERM_SHIFT + 216 /* (( */
# define TERM_DBL_RPARENTHESIS  		TERM_SHIFT + 217 /* )) */
# define TERM_LBRACKET          		TERM_SHIFT + 218 /* [ */
# define TERM_RBRACKET          		TERM_SHIFT + 219 /* ] */
# define TERM_LPARENTHESIS      		TERM_SHIFT + 220 /* ( */
# define TERM_RPARENTHESIS      		TERM_SHIFT + 221 /* ) */
# define TERM_SEMI              		TERM_SHIFT + 222 /* ; */
# define TERM_SINGLE_QUOTE      		TERM_SHIFT + 223 /* ' */
# define TERM_QUOTE             		TERM_SHIFT + 224 /* " */
# define TERM_HASH              		TERM_SHIFT + 225 /* # */
# define TERM_AND               		TERM_SHIFT + 242 /* & */
# define TERM_DSEMI             		TERM_SHIFT + 243 /* ;; */
# define TERM_NOT               		TERM_SHIFT + 245 /* ! */
# define TERM_PIPE              		TERM_SHIFT + 246 /* | */

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

#endif
