/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:08:43 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/22 19:38:35 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPR_H
# define EXPR_H

# include <stdint.h>
# include <stdio.h>
# include "lexer.h"

/*
 **
 ** 123		NUM
 ** var		VAR
 ** (1+2)	EXPR
 **
 **		/ ***
 **		UNARY OPERATORS
 **		/ ***
 **
 ** ++	POSTINC
 ** --	POSTDEC
 ** []	ARRAY
 ** [	OARRAY
 ** ]	CARRAY
 ** )	OBRACKET
 ** (	CBRACKET
 **
 ** ++	PREINC
 ** --	PREDEC
 ** +	UPLUS
 ** -	UMINUS
 ** !	LNOT
 ** ~	BNOT
 **
 **		/ ***
 **		BINARY AND TERNARY OPERATORS
 **		/ ***
 **
 ** **	POWER		---1---
 **
 ** *	MUL			---2---
 ** /	DIV
 ** %	MOD
 **
 ** +	ADD			---3---
 ** -	SUB
 **
 ** <<	LSH			---4---
 ** >>	RSH
 **
 ** <	GT			---5---
 ** <=	GEQ
 ** >	LT
 ** >=	LEQ
 **
 **	==	EQ			---6---
 **	!=	NEQ
 **
 ** &	BAND		---7---
 **
 ** ^	BXOR		---8---
 **
 ** |	BOR			---9---
 **
 ** &&	LAND		---10---
 **
 ** ||	LOR			---11---
 **
 ** ?:	COND		---13---
 ** '?'	QUES
 ** ':'	COL
 **
 ** =	ASSIGN		---14---
 ** +=	ADDASGN
 ** -=	SUBASGN
 ** *=	MULASGN
 ** /=	DIVASGN
 ** %=	MODASGN
 ** <<=	LSHASGN
 ** >>=	RSHASGN
 ** &=	ANDASGN
 ** ^=	XORASGN
 ** |=	ORASGN
 **
 ** ,	COMMA		---15---
 **
*/

# define VAR 10
# define NUM 11
# define EXPR 12

# define OPSHIFT		15

# define ADD			OPSHIFT + 0
# define SUB			OPSHIFT + 1
# define DIV			OPSHIFT + 2
# define MOD			OPSHIFT + 3
# define POWER			OPSHIFT + 4
# define MUL			OPSHIFT + 5
# define LSH			OPSHIFT + 6
# define RSH			OPSHIFT + 7
# define GT				OPSHIFT + 8
# define GEQ			OPSHIFT + 9
# define LT				OPSHIFT + 10
# define LEQ			OPSHIFT + 11
# define EQ				OPSHIFT + 12
# define NEQ			OPSHIFT + 13
# define BAND			OPSHIFT + 14
# define BXOR			OPSHIFT + 15
# define BOR			OPSHIFT + 16
# define LAND			OPSHIFT + 17
# define LOR 			OPSHIFT + 18
# define COND 			OPSHIFT + 19
# define QUES 			OPSHIFT + 20
# define COL			OPSHIFT + 21
# define ASSIGN			OPSHIFT + 22
# define ADDASGN		OPSHIFT + 23
# define SUBASGN		OPSHIFT + 24
# define MULASGN		OPSHIFT + 25
# define DIVASGN		OPSHIFT + 26
# define MODASGN		OPSHIFT + 27
# define LSHASGN		OPSHIFT + 28
# define RSHASGN		OPSHIFT + 29
# define ANDASGN		OPSHIFT + 30
# define XORASGN		OPSHIFT + 31
# define ORASGN			OPSHIFT + 32
# define COMMA			OPSHIFT + 33

# define ARRAY			OPSHIFT + 34
# define POSTINC		OPSHIFT + 35
# define POSTDEC		OPSHIFT + 36
# define OBRACKET		OPSHIFT + 37
# define CBRACKET		OPSHIFT + 38
# define OARRAY			OPSHIFT + 39
# define CARRAY			OPSHIFT + 40
# define PREINC			OPSHIFT + 41
# define PREDEC			OPSHIFT + 42
# define UMINUS			OPSHIFT + 43
# define UPLUS			OPSHIFT + 44
# define LNOT			OPSHIFT + 45
# define BNOT			OPSHIFT + 46

# define INC			OPSHIFT + 47 // ++
# define DEC			OPSHIFT + 48 // --
# define NOT			OPSHIFT + 50 // !
# define PLUS			OPSHIFT + 51 // +
# define MINUS			OPSHIFT + 52 // -
# define HASH			OPSHIFT + 53 // #
# define ALLINDEX		OPSHIFT + 54 // * in array index

typedef struct			s_astree
{
	int				type;
	char			*content;
	struct s_astree	*left;
	struct s_astree	*right;
}						t_astree;

extern unsigned int		g_curtok;
extern void				*g_tokens;

t_astree				*expr(void);
t_astree				*expr_rest(void);
t_astree				*expr2(void);
t_astree				*expr3(void);
t_astree				*expr4(void);
t_astree				*expr4_rest(void);
t_astree				*expr5(void);
t_astree				*expr5_rest(void);
t_astree				*expr6(void);
t_astree				*expr6_rest(void);
t_astree				*expr7(void);
t_astree				*expr7_rest(void);
t_astree				*expr8(void);
t_astree				*expr8_rest(void);
t_astree				*expr9(void);
t_astree				*expr9_rest(void);
t_astree				*expr10(void);
t_astree				*expr10_rest(void);
t_astree				*expr11(void);
t_astree				*expr11_rest(void);
t_astree				*expr12(void);
t_astree				*expr12_rest(void);
t_astree				*expr13(void);
t_astree				*expr13_rest(void);
t_astree				*expr14(void);
t_astree				*expr14_rest(void);
t_astree				*pre_unary(void);
t_astree				*preincdec(void);
t_astree				*postincdec(void);
t_astree				*postincdec_rest(void);
t_astree				*operand(void);
t_astree				*variable(void);
t_astree				*array(void);
t_astree				*substitution();
void					print_astree(t_astree *root);

#endif
