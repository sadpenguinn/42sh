/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminals.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 20:52:51 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/21 15:51:30 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINALS_H
# define TERMINALS_H

# define SHIFT              	50

# define DO                		SHIFT + 3 /* do */
# define DONE              		SHIFT + 5 /* done */
# define CASE              		SHIFT + 9 /* case */
# define ELIF              		SHIFT + 13 /* elif */
# define ELSE              		SHIFT + 15 /* else */
# define ESAC              		SHIFT + 18 /* esac */
# define FUNCTION          		SHIFT + 26 /* function */
# define FOR               		SHIFT + 28 /* for */
# define SELECT            		SHIFT + 31 /* select */
# define FI                		SHIFT + 32 /* fi */
# define IN                		SHIFT + 34 /* in */
# define IF                		SHIFT + 36 /* if */
# define THEN              		SHIFT + 40 /* then */
# define UNTIL             		SHIFT + 45 /* until */
# define WHILE             		SHIFT + 52 /* while */
# define WORD              		SHIFT + 53 /* word */
# define NEWLINE           		SHIFT + 54 /* \n */
# define SPACE             		SHIFT + 56 /* sp */
# define TAB             		SHIFT + 56 /* tab */
# define LESS              		SHIFT + 57 /* < */
# define GREAT             		SHIFT + 58 /* > */
# define COMMENT           		SHIFT + 60 /* comment */
# define DLESS             		SHIFT + 61 /* << */
# define DGREAT            		SHIFT + 62 /* >> */
# define DLESSDASH         		SHIFT + 64 /* <<- */
# define CLOBBER           		SHIFT + 65 /* >| */
# define PIPEAND				SHIFT + 66 /* |& */
# define GREATAND          		SHIFT + 68 /* &> */
# define SEMI              		SHIFT + 69 /* ; */
# define AND_IF            		SHIFT + 70 /* && */
# define LESSGREAT         		SHIFT + 71 /* <> */
# define LESSAND           		SHIFT + 73 /* <& */
# define DSEMI             		SHIFT + 75 /* ;; */
# define PIPE              		SHIFT + 87 /* | */
# define OBRACKET	     		SHIFT + 88 /* ( */
# define CBRACKET	      		SHIFT + 89 /* ) */
# define OBRACE            		SHIFT + 90 /* { */
# define CBRACE            		SHIFT + 91 /* } */
# define COND					SHIFT + 93 /* [ ... ] */
# define ARITH					SHIFT + 96 /* (( ... )) */

# define OR_IF             		SHIFT + 222 /* || */
# define AND               		SHIFT + 258 /* & */
# define NOT               		SHIFT + 261 /* ! */
# define CMDREDIR				SHIFT + 264
# define LIST1					SHIFT + 267
# define LIST2					SHIFT + 268
# define LIST3					SHIFT + 269
# define TOKEOF					SHIFT + 270
# define REST					SHIFT + 272
# define PIPECMD				SHIFT + 273
# define NUMBER					SHIFT + 274
# define REDIRECTION			SHIFT + 275
# define TLESS					SHIFT + 266 /* <<< */
# define COMMAND				SHIFT + 276
# define ASSIGMENT_WORD			SHIFT + 277

/*
** Unused defines
*/

/*# define DBL_LBRACKET      		SHIFT + 230 *//* [[ *//*
# define DBL_RBRACKET      		SHIFT + 231 *//* ]] *//*
# define DBL_LPARENTHESIS  		SHIFT + 232 *//* (( *//*
# define DBL_RPARENTHESIS  		SHIFT + 233 *//* )) *//*
# define LBRACKET          		SHIFT + 234 *//* [ *//*
# define RBRACKET          		SHIFT + 235 *//* ] *//*
# define SINGLE_QUOTE      		SHIFT + 239 *//* ' *//*
# define QUOTE             		SHIFT + 240 *//* " *//*
# define HASH              		SHIFT + 241 *//* # */

#endif
