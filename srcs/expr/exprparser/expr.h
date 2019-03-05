/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:08:43 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/22 21:34:09 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPR_H
# define EXPR_H

# include <stdint.h>
# include <stdio.h>
# include "exprlexer.h"
# include "terminals.h"

/*
**	TYPES FOR LEXER
**
**	123	EX_NUM
**	var	EX_VAR
**	**	EX_POW
**	*	EX_MUL
**	/	EX_DIV
**	%	EX_MOD
**	+	EX_ADD
**	-	EX_SUB
**	<<	EX_LSH
**	>>	EX_RSH
**	<	EX_GT
**	<=	EX_GEQ
**	>	EX_LT
**	>=	EX_LEQ
**	==	EX_EQ
**	!=	EX_NEQ
**	&	EX_BAND
**	^	EX_XOR
**	|	EX_BOR
**	&&	EX_LAND
**	||	EX_LOR
**	?	EX_QUES
**	:	EX_COL
**	=	EX_ASSIGN
**	+=	EX_ADDASN
**	-=	EX_SUBASN
**	*=	EX_MULASN
**	/=	EX_DIVASN
**	%=	EX_MODASN
**	<<=	EX_LSHASN
**	>>=	EX_RSHASN
**	&=	EX_ANDASN
**	^=	EX_XORASN
**	|=	EX_ORASN
**	,	EX_COMMA
**	[	EX_OARRAY
**	]	EX_CARRAY
**	)	EX_OBRACKET
**	(	EX_CBRACKET
**	++	EX_INC
**	--	EX_DEC
**	+	EX_PLUS
**	-	EX_UMINUS
**	!	EX_LNOT
**	~	EX_BNOT
*/

/*
**
**	TYPES FOR PARSER
**
**	123		EX_NUM
**	var		EX_VAR
**	(1+2)	EX_EXPR
**
**		/ ***
**		UNARY OPERATORS
**		/ ***
**
**	++	EX_POSTINC
**	--	EX_POSTDEC
**	[]	ARRAY
**
**	++	EX_PREINC
**	--	EX_PREDEC
**	+	EX_UPLUS
**	-	EX_UMINUS
**	!	EX_LNOT
**	~	EX_BNOT
**
**		/ ***
**		BINARY AND TERNARY OPERATORS
**		/ ***
**
**	**	EX_POW		---1---
**
**	*	EX_MUL		---2---
**	/	EX_DIV
**	%	EX_MOD
**
**	+	EX_ADD		---3---
**	-	EX_SUB
**
**	<<	EX_LSH		---4---
**	>>	EX_RSH
**
**	<	EX_GT		---5---
**	<=	EX_GEQ
**	>	EX_LT
**	>=	EX_LEQ
**
**	==	EX_EQ		---6---
**	!=	EX_NEQ
**
**	&	EX_BAND		---7---
**
**	^	EX_XOR		---8---
**
**	|	EX_BOR		---9---
**
**	&&	EX_LAND		---10---
**
**	||	EX_LOR		---11---
**
**	?:	EX_COND		---13---
**	'?'	EX_QUES
**	':'	EX_COL
**
**	=	EX_ASSIGN	---14---
**	+=	EX_ADDASN
**	-=	EX_SUBASN
**	*=	EX_MULASN
**	/=	EX_DIVASN
**	%=	EX_MODASN
**	<<=	EX_LSHASN
**	>>=	EX_RSHASN
**	&=	EX_ANDASN
**	^=	EX_XORASN
**	|=	EX_ORASN
**
**	,	EX_COMMA	---15---
**
*/



typedef struct			s_astree
{
	int				type;
	char			*content;
	struct s_astree	*left;
	struct s_astree	*right;
}						t_astree;

extern unsigned int		g_curtok;
extern void				*g_tokens;

extern unsigned int		g_excurtok;
extern void				*g_extokens;

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
