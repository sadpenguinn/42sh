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
# define NOT               		SHIFT + 104 /* ! */

/*
* Internal states for parser
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
** Expr terminals
*/

# define EXPR_DVAR				SHIFT + 3 /* $VAR */
# define EXPR_DNUM				SHIFT + 4 /* $123 */
# define EXPR_VAR				SHIFT + 5 /* VAR  */
# define EXPR_NUM				SHIFT + 6 /* 123  */
# define EXPR_PLUS				SHIFT + 7 /*   +  */
# define EXPR_PPLUS				SHIFT + 8 /*  ++  */
# define EXPR_MINUS				SHIFT + 9 /*   -  */
# define EXPR_MMINUS			SHIFT + 10 /* --  */
# define EXPR_MULT				SHIFT + 11 /*  *  */
# define EXPR_DIV				SHIFT + 12 /*  /  */
# define EXPR_MOD				SHIFT + 13 /*  %  */
# define EXPR_GREAT				SHIFT + 14 /*  >  */
# define EXPR_GREATEQ			SHIFT + 15 /*  >= */
# define EXPR_LESS				SHIFT + 16 /*  <  */
# define EXPR_LESSEQ			SHIFT + 17 /*  <= */
# define EXPR_NOTEQ				SHIFT + 19 /*  != */
# define EXPR_EQ				SHIFT + 21 /*  == */
# define EXPR_AND				SHIFT + 23 /*  && */
# define EXPR_OR				SHIFT + 25 /*  || */


#endif
