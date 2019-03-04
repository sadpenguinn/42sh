/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplite.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:01:24 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/04 20:19:08 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTOCOMPLITE_H
# define AUTOCOMPLITE_H

# include "readline.h"
# include "libft.h"
# include "shell.h"
# include "execute.h"
# include "parser.h"
# include <stdio.h>

# define ERROR_AUTOCOMLITE	0
# define ENV_AUTOCOMLITE	1
# define OTHER_AUTOCOMLITE	2

char    **autocomplite(t_line *line_info, int pos);

#endif