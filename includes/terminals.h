/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminals.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 20:52:51 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/20 20:57:42 by nkertzma         ###   ########.fr       */
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

# define AND_IF            		SHIFT + 221 /* && */
# define OR_IF             		SHIFT + 222 /* || */
# define LESSAND           		SHIFT + 226 /* <& */
# define GREATAND          		SHIFT + 227 /* &> */
# define OBRACE            		SHIFT + 212 /* { */
# define CBRACE            		SHIFT + 213 /* } */
# define DBL_LBRACKET      		SHIFT + 214 /* [[ */
# define DBL_RBRACKET      		SHIFT + 215 /* ]] */
# define DBL_LPARENTHESIS  		SHIFT + 216 /* (( */
# define DBL_RPARENTHESIS  		SHIFT + 217 /* )) */
# define LBRACKET          		SHIFT + 218 /* [ */
# define RBRACKET          		SHIFT + 219 /* ] */
# define OBRACKET	     		SHIFT + 220 /* ( */
# define CBRACKET	      		SHIFT + 221 /* ) */
# define SEMI              		SHIFT + 222 /* ; */
# define SINGLE_QUOTE      		SHIFT + 223 /* ' */
# define QUOTE             		SHIFT + 224 /* " */
# define HASH              		SHIFT + 225 /* # */
# define AND               		SHIFT + 242 /* & */
# define DSEMI             		SHIFT + 243 /* ;; */
# define NOT               		SHIFT + 245 /* ! */
# define PIPE              		SHIFT + 246 /* | */
# define ARITH					SHIFT + 247
# define CMDREDIR				SHIFT + 248
# define COND					SHIFT + 249 /* [[ ... ]] */
# define LIST1					SHIFT + 251
# define LIST2					SHIFT + 252
# define LIST3					SHIFT + 253
# define TOKEOF					SHIFT + 254
# define PIPEAND				SHIFT + 255 /* |& */
# define REST					SHIFT + 256
# define PIPECMD				SHIFT + 257
# define NUMBER					SHIFT + 258
# define REDIRECTION			SHIFT + 259
# define TLESS					SHIFT + 250 /* <<< */
# define COMMAND				SHIFT + 260
# define ASSIGMENT_WORD			SHIFT + 261

#endif
