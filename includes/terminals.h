/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminals.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 20:52:51 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/26 17:32:22 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINALS_H
# define TERMINALS_H

# define SHIFT              	50

/*
* Internal states for lexer & parser
*/

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
# define AND               		SHIFT + 55 /* & */
# define SPACE             		SHIFT + 56 /* sp */
# define TAB             		SHIFT + 56 /* tab */
# define LESS              		SHIFT + 57 /* < */
# define GREAT             		SHIFT + 58 /* > */
# define COMMENT           		SHIFT + 60 /* comment */
# define DLESS             		SHIFT + 61 /* << */
# define DGREAT            		SHIFT + 62 /* >> */
# define DLESSDASH         		SHIFT + 64 /* <<- */
# define CLOBBER           		SHIFT + 65 /* >| */
# define OR_IF					SHIFT + 66 /* || */
# define GREATAND          		SHIFT + 68 /* >& */
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
# define NOT               		SHIFT + 104 /* ! */

/*
**	Internal states for parser
*/

# define CMDREDIR				SHIFT + 110
# define LIST1					SHIFT + 111
# define LIST2					SHIFT + 112
# define LIST3					SHIFT + 113
# define TOKEOF					SHIFT + 114
# define REST					SHIFT + 115
# define PIPECMD				SHIFT + 116
# define NUMBER					SHIFT + 117
# define REDIRECTION			SHIFT + 118
# define COMMAND				SHIFT + 119
# define ASSIGMENT_WORD			SHIFT + 120
# define SUBSHELL				SHIFT + 121

/*
**	Types for expression
*/

# define OPSHIFT		150

# define EX_VAR					OPSHIFT + 38 /* VAR */
# define EX_NUM					OPSHIFT + 39 /* 123 */
# define EX_EXPR				OPSHIFT + 5555552
# define EX_INC					OPSHIFT + 4 /* ++ */
# define EX_DEC					OPSHIFT + 7 /* -- */
# define EX_ADD					OPSHIFT + 2 /* + */
# define EX_SUB					OPSHIFT + 6 /* - */
# define EX_DIV					OPSHIFT + 11 /* / */
# define EX_MOD					OPSHIFT + 13 /* % */
# define EX_POW					OPSHIFT + 55523423
# define EX_MUL					OPSHIFT + 8 /* * */
# define EX_LSH					OPSHIFT + 19 /* << */
# define EX_RSH					OPSHIFT + 14 /* >> */
# define EX_GT					OPSHIFT + 17 /* > */
# define EX_GEQ					OPSHIFT + 18 /* >= */
# define EX_LT					OPSHIFT + 21 /* < */
# define EX_LEQ					OPSHIFT + 22 /* <= */
# define EX_EQ					OPSHIFT + 26 /* == */
# define EX_NEQ					OPSHIFT + 24 /* != */
# define EX_BAND				OPSHIFT + 27 /* & */
# define EX_XOR					OPSHIFT + 33 /* ^ */
# define EX_BOR					OPSHIFT + 30 /* | */
# define EX_LAND				OPSHIFT + 28 /* && */
# define EX_LOR 				OPSHIFT + 31 /* || */
# define EX_COND				OPSHIFT + 555524
# define EX_QUES				OPSHIFT + 35 /* ? */
# define EX_COL					OPSHIFT + 36 /* : */
# define EX_ASSIGN				OPSHIFT + 25 /* = */
# define EX_ADDASN				OPSHIFT + 3 /* += */
# define EX_SUBASN				OPSHIFT + 5 /* -= */
# define EX_MULASN				OPSHIFT + 10 /* *= */
# define EX_DIVASN				OPSHIFT + 12 /* /= */
# define EX_MODASN				OPSHIFT + 15 /* %= */
# define EX_LSHASN				OPSHIFT + 26 /* <<= */
# define EX_RSHASN				OPSHIFT + 16 /* >>= */
# define EX_ANDASN				OPSHIFT + 29 /* &= */
# define EX_XORASN				OPSHIFT + 34 /* ^= */
# define EX_ORASN				OPSHIFT + 32 /* |= */
# define EX_COMMA				OPSHIFT + 46 /* , */
# define EX_OBRACKET			OPSHIFT + 44 /* ( */
# define EX_CBRACKET			OPSHIFT + 45 /* ) */
# define EX_OARRAY				OPSHIFT + 42 /* [ */
# define EX_CARRAY				OPSHIFT + 43 /* ] */
# define EX_UMINUS				OPSHIFT + 555547
# define EX_UPLUS				OPSHIFT + 555548
# define EX_LNOT				OPSHIFT + 555549
# define EX_BNOT				OPSHIFT + 555545
# define EX_SPACE				OPSHIFT + 41 /* sp */
# define EX_TAB					OPSHIFT + 41 /* \t */
# define EX_NEWLINE				OPSHIFT + 41 /* \n */

#endif
