/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:08:43 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/22 13:31:33 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPR_H
# define EXPR_H

# include <stdint.h>
# include <stdio.h>
# include "headers/lexer.h"

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

/* # define	NUM 222 */
# define VAR 333
# define NUM 888
# define EXPR 444

# define OPSHIFT		200

# define POWER			OPSHIFT + 1
# define MUL			OPSHIFT + 2
# define DIV			OPSHIFT + 3
# define MOD			OPSHIFT + 4
# define ADD			OPSHIFT + 5
# define SUB			OPSHIFT + 6
# define LSH			OPSHIFT + 7
# define RSH			OPSHIFT + 8
# define GT				OPSHIFT + 9
# define GEQ			OPSHIFT + 10
# define LT				OPSHIFT + 11
# define LEQ			OPSHIFT + 12
# define EQ				OPSHIFT + 13
# define NEQ			OPSHIFT + 14
# define BAND			OPSHIFT + 15
# define BXOR			OPSHIFT + 16
# define BOR			OPSHIFT + 17
# define LAND			OPSHIFT + 18
# define LOR 			OPSHIFT + 19
# define COND 			OPSHIFT + 20
# define QUES 			OPSHIFT + 21
# define COL			OPSHIFT + 22
# define ASSIGN			OPSHIFT + 23
# define ADDASGN		OPSHIFT + 24
# define SUBASGN		OPSHIFT + 25
# define MULASGN		OPSHIFT + 26
# define DIVASGN		OPSHIFT + 27
# define MODASGN		OPSHIFT + 28
# define LSHASGN		OPSHIFT + 29
# define RSHASGN		OPSHIFT + 30
# define ANDASGN		OPSHIFT + 31
# define XORASGN		OPSHIFT + 32
# define ORASGN			OPSHIFT + 33
# define COMMA			OPSHIFT + 34

# define ARRAY			OPSHIFT + 35
# define POSTINC		OPSHIFT + 36
# define POSTDEC		OPSHIFT + 37
# define OBRACKET		OPSHIFT + 38
# define CBRACKET		OPSHIFT + 39
# define OARRAY			OPSHIFT + 40
# define CARRAY			OPSHIFT + 41
# define PREINC			OPSHIFT + 42
# define PREDEC			OPSHIFT + 43
# define UMINUS			OPSHIFT + 44
# define UPLUS			OPSHIFT + 45
# define LNOT			OPSHIFT + 47
# define BNOT			OPSHIFT + 48

#define INC			OPSHIFT + 49 // ++
#define DEC			OPSHIFT + 50 // --
#define NOT			OPSHIFT + 51 // !
#define PLUS		OPSHIFT + 52 // +
#define MINUS		OPSHIFT + 53 // -
#define HASH		OPSHIFT + 54 // #
#define ALLINDEX	OPSHIFT + 55 // * in array index


typedef struct	s_astree
{
	int				type;
	char			*content;
	struct s_astree	*left;
	struct s_astree	*right;
}				t_astree;

extern unsigned int		g_curtok;
extern void				*g_tokens;

t_astree	*expr(void);
t_astree	*expr_rest(void);
t_astree	*expr2(void);
t_astree	*expr3(void);
t_astree	*expr4(void);
t_astree	*expr4_rest(void);
t_astree	*expr5(void);
t_astree	*expr5_rest(void);
t_astree	*expr6(void);
t_astree	*expr6_rest(void);
t_astree	*expr7(void);
t_astree	*expr7_rest(void);
t_astree	*expr8(void);
t_astree	*expr8_rest(void);
t_astree	*expr9(void);
t_astree	*expr9_rest(void);
t_astree	*expr10(void);
t_astree	*expr10_rest(void);
t_astree	*expr11(void);
t_astree	*expr11_rest(void);
t_astree	*expr12(void);
t_astree	*expr12_rest(void);
t_astree	*expr13(void);
t_astree	*expr13_rest(void);
t_astree	*expr14(void);
t_astree	*expr14_rest(void);
t_astree	*pre_unary(void);
t_astree	*preincdec(void);
t_astree	*postincdec(void);
t_astree	*postincdec_rest(void);
t_astree	*operand(void);
t_astree	*variable(void);
t_astree	*array(void);
t_astree	*substitution();
void		print_astree(t_astree *root);

#endif
