/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:08:43 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/11 17:31:59 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPR_H
# define EXPR_H

# include <stdint.h>
# include <stdio.h>
# include "lexer.h"

/* #define STR			0	/1* string *1/ */
/* #define NUM			0	/1* number *1/ */

/* #define OP_ASSIGN	0	/1* op= expassign as in Posix.2 *1/ */

#define WORD		0	/* operand */
#define VAR			1	/* variable */

#define LSHEQ	    2	/* <<= */
#define RSHEQ		3	/* >>= */

#define INC			4	/* var++ */
#define DEC			5	/* var-- */
#define POWER		6	/* ** exp1 ** exp2 */
#define LSH			7	/* << Left SHift */
#define RSH			8	/* >> Right SHift */
#define LEQ			9	/* <= */
#define GEQ			10	/* >= */
#define EQEQ		11	/* "==" */
#define NEQ			12	/* "!=" */
#define LAND		13	/* && Logical AND */
#define LOR			14	/* || Logical OR */
#define ADDEQ       15	/* += */
#define SUBEQ       16	/* -= */
#define MULEQ       17	/* *= */
#define DIVEQ       18	/* /= */
#define MODEQ       19	/* %= */
#define BANDEQ      20	/* &= */
#define BOREQ       21	/* |= */
#define BXOREQ      22	/* ^= */

#define LPAR		23	/* ( */
#define RPAR		24	/* ) */
#define LSPAR		25	/* [ */
#define RSPAR		26	/* ] */
#define NOT			27	/* ! */
#define BNOT		28	/* ~ Bitwise NOT; Two's complement. */
#define MUL			29	/* * */
#define DIV			30	/* / */
#define MOD			31	/* % */
#define PLUS 		32	/* + */
#define MINUS 		33	/* - */
#define LT			34	/* < */
#define GT			35	/* > */
#define BAND		36	/* & Bitwise AND */
#define BXOR		37	/* ^ Bitwise eXclusive OR. */
#define BOR			38	/* | Bitwise OR. */
#define QUES		39	/* ? */
#define COL			40	/* : */
#define EQ			41	/* = */

/*
 ** INC			++
 ** DEC			--
 ** LPAR		(
 ** RPAR		)
 ** LSPAR		[
 ** RSPAR		]
 ** NOT			!
 ** BNOT		~
 ** POWER		**
 ** MUL			*
 ** DIV			/
 ** MOD			%
 ** ADD 		+
 ** SUB 		-
 ** LSH			<<
 ** RSH			>>
 ** LT			<
 ** LEQ			<=
 ** GT			>
 ** GEQ			>=
 ** EQEQ		==
 ** NEQ			!=
 ** BAND		&
 ** BXOR		^
 ** BOR			|
 ** LAND		&&
 ** LOR			||
 ** QUES		?
 ** COL			:
 ** EQ			=
 ** ADDEQ       +=
 ** SUBEQ       -=
 ** MULEQ       *=
 ** DIVEQ       /=
 ** MODEQ       %=
 ** LSHEQ	    <<=
 ** RSHEQ		>>=
 ** BANDEQ      &=
 ** BOREQ       |=
 ** BXOREQ      ^=
 ** COMMA		,
*/

typedef struct	s_astree
{
	int				type;
	void			*val;
	struct s_astree	*left;
	struct s_astree	*right;
}				t_astree;

typedef struct s_extok
{
	int type;
	char *word;
	struct s_extok next;

} t_extok;

t_astree	*expr(void);
t_astree	*operand(void);
t_astree	*num(void);
t_astree	*digit(void);

#endif
