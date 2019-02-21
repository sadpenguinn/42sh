/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminals.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 20:52:51 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/21 15:01:08 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINALS_H
#define TERMINALS_H

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
# define LESSGREAT         		SHIFT + 71 /* <> */
# define SEMI              		SHIFT + 69 /* ; */

# define AND_IF            		SHIFT + 221 /* && */
# define OR_IF             		SHIFT + 222 /* || */
# define LESSAND           		SHIFT + 226 /* <& */
# define GREATAND          		SHIFT + 227 /* &> */
# define OBRACE            		SHIFT + 228 /* { */
# define CBRACE            		SHIFT + 229 /* } */
# define DBL_LBRACKET      		SHIFT + 230 /* [[ */
# define DBL_RBRACKET      		SHIFT + 231 /* ]] */
# define DBL_LPARENTHESIS  		SHIFT + 232 /* (( */
# define DBL_RPARENTHESIS  		SHIFT + 233 /* )) */
# define LBRACKET          		SHIFT + 234 /* [ */
# define RBRACKET          		SHIFT + 235 /* ] */
# define OBRACKET	     		SHIFT + 236 /* ( */
# define CBRACKET	      		SHIFT + 237 /* ) */
# define SINGLE_QUOTE      		SHIFT + 239 /* ' */
# define QUOTE             		SHIFT + 240 /* " */
# define HASH              		SHIFT + 241 /* # */
# define AND               		SHIFT + 258 /* & */
# define DSEMI             		SHIFT + 259 /* ;; */
# define NOT               		SHIFT + 261 /* ! */
# define PIPE              		SHIFT + 262 /* | */
# define ARITH					SHIFT + 263
# define CMDREDIR				SHIFT + 264
# define COND					SHIFT + 265 /* [[ ... ]] */
# define LIST1					SHIFT + 267
# define LIST2					SHIFT + 268
# define LIST3					SHIFT + 269
# define TOKEOF					SHIFT + 270
# define PIPEAND				SHIFT + 271 /* |& */
# define REST					SHIFT + 272
# define PIPECMD				SHIFT + 273
# define NUMBER					SHIFT + 274
# define REDIRECTION			SHIFT + 275
# define TLESS					SHIFT + 266 /* <<< */
# define COMMAND				SHIFT + 276
# define ASSIGMENT_WORD			SHIFT + 277

#endif
