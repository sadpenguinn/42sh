/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 19:15:08 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/19 22:08:14 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include <inttypes.h>
# include "expression.h"
# include "terminals.h"

# define CL_DIVZERO 1

extern intmax_t	(*operators[500])(intmax_t operator, t_astree *node);

intmax_t		calc(t_astree *root);
intmax_t		calcerror(int err);

intmax_t		op_add(intmax_t operator, t_astree *node);
intmax_t		op_sub(intmax_t operator, t_astree *node);
intmax_t		op_div(intmax_t operator, t_astree *node);
intmax_t		op_mod(intmax_t operator, t_astree *node);
intmax_t		op_mul(intmax_t operator, t_astree *node);
intmax_t		op_pow(intmax_t operator, t_astree *node);
intmax_t		op_lsh(intmax_t operator, t_astree *node);
intmax_t		op_rsh(intmax_t operator, t_astree *node);
intmax_t		op_gt(intmax_t operator, t_astree *node);
intmax_t		op_geq(intmax_t operator, t_astree *node);
intmax_t		op_lt(intmax_t operator, t_astree *node);
intmax_t		op_leq(intmax_t operator, t_astree *node);
intmax_t		op_eq(intmax_t operator, t_astree *node);
intmax_t		op_neq(intmax_t operator, t_astree *node);
intmax_t		op_band(intmax_t operator, t_astree *node);
intmax_t		op_xor(intmax_t operator, t_astree *node);
intmax_t		op_bor(intmax_t operator, t_astree *node);
intmax_t		op_land(intmax_t operator, t_astree *node);
intmax_t		op_lor(intmax_t operator, t_astree *node);

#endif

/*
**	     ROOT
**      /    \
**	LEFT      RIGHT
**
**	LEFT: EX_NUM, EX_VAR, EX_EXPR, EX_QUES, EX_ASSIGN
**	LEFT: EX_ADD, EX_SUB, EX_LNOT, EX_BNOT
**	LEFT: EX_INC, EX_DEC
**
**	RIGHT: special
*/
