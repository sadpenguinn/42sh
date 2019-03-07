/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_style.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:34:06 by narchiba          #+#    #+#             */
/*   Updated: 2019/02/26 17:26:07 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void	add_lines_prompt_style(void)
{
	array_add(TEXT_BOLD, strlen(TEXT_BOLD));
}

void	add_cur_line_prompt_style(void)
{
	array_add(TEXT_BOLD, strlen(TEXT_BOLD));
	array_add(TEXT_COLOR_RED, strlen(TEXT_COLOR_RED));
}

void	add_prompt_style(void)
{
	array_add(TEXT_BOLD, strlen(TEXT_BOLD));
	array_add(TEXT_COLOR_BLUE, strlen(TEXT_COLOR_BLUE));
}

void	add_shell_name_style(void)
{
	array_add(TEXT_BOLD, strlen(TEXT_BOLD));
	array_add(TEXT_COLOR_GREEN, strlen(TEXT_COLOR_GREEN));
}
