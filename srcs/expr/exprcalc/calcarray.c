/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_arrfunc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:08:37 by nkertzma          #+#    #+#             */
/*   Updated: 2019/01/23 11:17:07 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calc.h"

intmax_t	op_none(intmax_t o, t_astree *n)
{
	(void)o;
	(void)n;
	return (0);
}

intmax_t (*g_operators[])(intmax_t operator, t_astree *node) = {
	op_none,
	op_none,
	op_add,
	op_none,
	op_none,
	op_none,
	op_sub,
	op_none,
	op_mul,
	op_pow,
	op_none,
	op_div,
	op_none,
	op_mod,
	op_rsh,
	op_none,
	op_none,
	op_gt,
	op_geq,
	op_lsh,
	op_none,
	op_lt,
	op_leq,
	op_none,
	op_neq,
	op_none,
	op_eq,
	op_band,
	op_land,
	op_none,
	op_bor,
	op_lor,
	op_none,
	op_xor,
};
