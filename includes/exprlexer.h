/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exprlexer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 17:42:57 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/26 17:32:22 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPRLEXER_H
# define EXPRLEXER_H

# include "lexer.h"

t_lexer		*exprlexer(char *str, size_t len);

#endif
