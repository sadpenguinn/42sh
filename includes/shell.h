/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:39:09 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/11 20:46:55 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
#define SHELL_H

# include <stdlib.h>
# include "libshell.h"
# include "libhash.h"

extern char 	**environ;
/*extern t_hshtb	**g_env;*/

# define INITIAL_ENV_HASH_SIZE	100

# define TERM_SHIFT              50
# define TERM_WORD              TERM_SHIFT + 0 /* word */
# define TERM_AND_IF            TERM_SHIFT + 1 /* && */
# define TERM_OR_IF             TERM_SHIFT + 2 /* || */
# define TERM_DLESSDASH         TERM_SHIFT + 3 /* <<- */
# define TERM_DLESS             TERM_SHIFT + 4 /* << */
# define TERM_DGREAT            TERM_SHIFT + 5 /* >> */
# define TERM_LESSAND           TERM_SHIFT + 6 /* <& */
# define TERM_GREATAND          TERM_SHIFT + 7 /* &> */
# define TERM_LESSGREAT         TERM_SHIFT + 8 /* <> */
# define TERM_CLOBBER           TERM_SHIFT + 9 /* >| */
# define TERM_LESS              TERM_SHIFT + 10 /* < */
# define TERM_GREAT             TERM_SHIFT + 11 /* > */
# define TERM_LBRACE            TERM_SHIFT + 12 /* { */
# define TERM_RBRACE            TERM_SHIFT + 13 /* } */
# define TERM_DBL_LBRACKET      TERM_SHIFT + 14 /* [[ */
# define TERM_DBL_RBRACKET      TERM_SHIFT + 15 /* ]] */
# define TERM_DBL_LPARENTHESIS  TERM_SHIFT + 16 /* (( */
# define TERM_DBL_RPARENTHESIS  TERM_SHIFT + 17 /* )) */
# define TERM_LBRACKET          TERM_SHIFT + 18 /* [ */
# define TERM_RBRACKET          TERM_SHIFT + 19 /* ] */
# define TERM_LPARENTHESIS      TERM_SHIFT + 20 /* ( */
# define TERM_RPARENTHESIS      TERM_SHIFT + 21 /* ) */
# define TERM_SEMI              TERM_SHIFT + 22 /* ; */
# define TERM_SINGLE_QUOTE      TERM_SHIFT + 23 /* ' */
# define TERM_QUOTE             TERM_SHIFT + 24 /* " */
# define TERM_HASH              TERM_SHIFT + 25 /* # */
# define TERM_IF                TERM_SHIFT + 26 /* if */
# define TERM_THEN              TERM_SHIFT + 27 /* then */
# define TERM_ELSE              TERM_SHIFT + 28 /* else */
# define TERM_ELIF              TERM_SHIFT + 29 /* elif */
# define TERM_FI                TERM_SHIFT + 30 /* fi */
# define TERM_DO                TERM_SHIFT + 31 /* do */
# define TERM_DONE              TERM_SHIFT + 32 /* done */
# define TERM_CASE              TERM_SHIFT + 33 /* case */
# define TERM_ESAC              TERM_SHIFT + 34 /* esac */
# define TERM_WHILE             TERM_SHIFT + 35 /* while */
# define TERM_UNTIL             TERM_SHIFT + 36 /* until */
# define TERM_FOR               TERM_SHIFT + 37 /* for */
# define TERM_FUNCTION          TERM_SHIFT + 38 /* function */
# define TERM_IN                TERM_SHIFT + 39 /* in */
# define TERM_SElECT            TERM_SHIFT + 40 /* select */
# define TERM_AND               TERM_SHIFT + 42 /* & */
# define TERM_DSEMI             TERM_SHIFT + 43 /* ;; */
# define TERM_NEWLINE           TERM_SHIFT + 54 /* \n */
# define TERM_NOT               TERM_SHIFT + 45 /* ! */
# define TERM_PIPE              TERM_SHIFT + 46 /* | */
# define TERM_SPACE             TERM_SHIFT + 47 /* sp */

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

#endif
