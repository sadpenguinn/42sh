/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 08:44:45 by narchiba          #+#    #+#             */
/*   Updated: 2019/02/07 08:45:56 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_H
# define READLINE_H

# define CSI "\e["
# define PROMPT_COLOR "\e[34m"
# define CURSOR_MOVE_START "\e[1G"
# define CURSOR_CLEAR_TO_END_SCREEN "\e[0J"
# define CURSOR_CLEAR_TO_START_SCREEN "\e[1J"
# define CURSOR_CLEAR_SCREEN "\ec"

typedef long long int t_uchar;

int     ft_readline(void);
t_uchar	get_next_symbol(void);
void    clear_screen_down(void);
void    save_cursor(void);
void    restore_cursor(void);

#endif
