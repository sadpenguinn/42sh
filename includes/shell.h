/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:39:09 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/18 13:53:50 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <stdlib.h>
# include "libshell.h"
# include "libhash.h"

extern t_hshtb	**g_hash_env;
extern t_hshtb	**g_path;

# define INITIAL_ENV_HASH_SIZE	100
# define INITIAL_PATH_HASH_SIZE	20

/*
** Shell error define like a standard C errno
*/
# define SHERR_ERR				0
# define SHERR_OK				1
# define SHERR_ENOENT			2

# define TERM_SHIFT              50

# define TERM_DO                TERM_SHIFT + 3 /* do */
# define TERM_DONE              TERM_SHIFT + 5 /* done */
# define TERM_CASE              TERM_SHIFT + 9 /* case */
# define TERM_ELIF              TERM_SHIFT + 13 /* elif */
# define TERM_ELSE              TERM_SHIFT + 15 /* else */
# define TERM_ESAC              TERM_SHIFT + 18 /* esac */
# define TERM_FUNCTION          TERM_SHIFT + 26 /* function */
# define TERM_FOR               TERM_SHIFT + 28 /* for */
# define TERM_SELECT            TERM_SHIFT + 31 /* select */
# define TERM_FI                TERM_SHIFT + 32 /* fi */
# define TERM_IN                TERM_SHIFT + 34 /* in */
# define TERM_IF                TERM_SHIFT + 36 /* if */
# define TERM_THEN              TERM_SHIFT + 40 /* then */
# define TERM_UNTIL             TERM_SHIFT + 45 /* until */
# define TERM_WHILE             TERM_SHIFT + 52 /* while */
# define TERM_WORD              TERM_SHIFT + 53 /* word */
# define TERM_NEWLINE           TERM_SHIFT + 54 /* \n */
# define TERM_SPACE             TERM_SHIFT + 56 /* sp */
# define TERM_TAB             	TERM_SHIFT + 56 /* tab */
# define TERM_LESS              TERM_SHIFT + 57 /* < */
# define TERM_GREAT             TERM_SHIFT + 58 /* > */
# define TERM_COMMENT           TERM_SHIFT + 60 /* comment */
# define TERM_DLESS             TERM_SHIFT + 61 /* << */
# define TERM_DGREAT            TERM_SHIFT + 62 /* >> */
# define TERM_DLESSDASH         TERM_SHIFT + 64 /* <<- */
# define TERM_CLOBBER           TERM_SHIFT + 65 /* >| */
# define TERM_LESSGREAT         TERM_SHIFT + 71 /* <> */

# define TERM_AND_IF            TERM_SHIFT + 221 /* && */
# define TERM_OR_IF             TERM_SHIFT + 222 /* || */
# define TERM_LESSAND           TERM_SHIFT + 226 /* <& */
# define TERM_GREATAND          TERM_SHIFT + 227 /* &> */
# define TERM_LBRACE            TERM_SHIFT + 212 /* { */
# define TERM_RBRACE            TERM_SHIFT + 213 /* } */
# define TERM_DBL_LBRACKET      TERM_SHIFT + 214 /* [[ */
# define TERM_DBL_RBRACKET      TERM_SHIFT + 215 /* ]] */
# define TERM_DBL_LPARENTHESIS  TERM_SHIFT + 216 /* (( */
# define TERM_DBL_RPARENTHESIS  TERM_SHIFT + 217 /* )) */
# define TERM_LBRACKET          TERM_SHIFT + 218 /* [ */
# define TERM_RBRACKET          TERM_SHIFT + 219 /* ] */
# define TERM_LPARENTHESIS      TERM_SHIFT + 220 /* ( */
# define TERM_RPARENTHESIS      TERM_SHIFT + 221 /* ) */
# define TERM_SEMI              TERM_SHIFT + 222 /* ; */
# define TERM_SINGLE_QUOTE      TERM_SHIFT + 223 /* ' */
# define TERM_QUOTE             TERM_SHIFT + 224 /* " */
# define TERM_HASH              TERM_SHIFT + 225 /* # */
# define TERM_AND               TERM_SHIFT + 242 /* & */
# define TERM_DSEMI             TERM_SHIFT + 243 /* ;; */
# define TERM_NOT               TERM_SHIFT + 245 /* ! */
# define TERM_PIPE              TERM_SHIFT + 246 /* | */

# define C_COLORS
# define C_DEFAULT "\x1b[0m"
# define C_BOLD "\x1b[1m"
# define C_LIGHT "\x1b[2m"
# define C_RM_LIGHT "\x1b[22m"
# define C_UNDERLINE "\x1b[4m"
# define C_RM_UNDERLINE "\x1b[24m"
# define C_BLINK "\x1b[5m"
# define C_RM_BLINK "\x1b[25m"

# define C_BLACK "\x1b[30m"
# define C_RED "\x1b[31m"
# define C_GREEN "\x1b[32m"
# define C_YELLOW "\x1b[33m"
# define C_BLUE "\x1b[34m"
# define C_PURPLE "\x1b[35m"
# define C_AQUA "\x1b[36m"
# define C_GRAY "\x1b[37m"

# define BG_BLACK "\x1b[40m"
# define BG_RED "\x1b[41m"
# define BG_GREEN "\x1b[42m"
# define BG_YELLOW "\x1b[43m"
# define BG_BLUE "\x1b[44m"
# define BG_PURPLE "\x1b[45m"
# define BG_AQUA "\x1b[46m"
# define BG_GRAY "\x1b[47m"

<<<<<<< HEAD
typedef struct			s_astree
{
	int				type;
	char			*content;
	struct s_astree	*left;
	struct s_astree	*right;
}						t_astree;

=======
void	init_hash_env(char **env);
void	init_path(void);
void 	destroy_hash_env(void);
void 	destroy_path(void);
>>>>>>> fb2c8db063a3a252e3a138d6f62c325c61eae674

#endif
