/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extention.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 16:50:55 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/02/19 20:42:01 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTENTION_H
# define EXTENTION_H

#include "libshell.h"

/*
** ${parameter:-word} 1
** ${parameter:=word} 2
** ${parameter:?word} 3
** ${parameter:+word} 4
** ${#parameter}      5
** ${parameter%}      6
** ${parameter%%}     7
** ${parameter#}      8
** ${parameter##}     9
*/

char	*get_content_of_expression(char *str);
char	*extention(char *str);

#endif
