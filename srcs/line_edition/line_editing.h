/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_editing.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 23:07:44 by sitlcead          #+#    #+#             */
/*   Updated: 2019/01/17 11:15:15 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_EDITING_H
# define LINE_EDITING_H

# include <stdlib.h>
# include <termios.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <time.h>

enum	keys
{
	UP = 0x415b1b, DOWN = 0x425b1b, RIGHT = 0x435b1b, LEFT = 0x445b1b,
	BS = 0x7f, DEL = 0x7e335b1b,
	HOME1 = 0x485b1b, END1 = 0x465b1b, HOME2 = 0x7e315b1b, END2 = 0x7e345b1b,
	ESC = 0x1b
};
enum	modes
{
	NORMAL_MODE = 1, VISUAL_MODE = 2, INSERT_MODE = 4
};
enum	allocation_params
{
	HISTORY_SIZE = 10, LINE_SIZE = 1024, RATIO = 2
};
enum	errors
{
	LINE_ALLOCATION_ERROR = 2, HISTORY_ALLOCATION_ERROR = 3
};

# define CTRL_V 026

typedef	struct	s_line
{
	char		*buf;
	int			len;
	int			pos;
	int			size;
}				t_line;

typedef	struct	s_history
{
	int			cur;
	int			len;
	int			size;
	t_line		**arr;
}				t_history;

typedef long long int t_uchar;

int		find_pos_left(const char *buf, int pos);
int		find_pos_right(const char *buf, int len, int pos);

int		move_cursor_left(int n);
int		move_cursor_right(int n);
int		move_cursor_to_pos(char *buf, int dest, int src);

int		move_pos_left(char *buf, int *len, int *pos);
int		move_pos_right(char *buf, int *len, int *pos);
int		move_pos_begin(char *buf, int *len, int *pos);
int		move_pos_end(char *buf, int *len, int *pos);
int		move_pos_next_alnum(char *buf, int len, int *pos);
int		move_pos_back_alnum(char *buf, int len, int *pos);
int		move_pos_next_word(char *buf, int len, int *pos);
int		move_pos_back_word(char *buf, int len, int *pos);

int		simple_line_edition(char *buf, int *len, int *pos, t_uchar c);
t_uchar	get_next_symbol(void);
int		output_line(char *buf, int *len, int *pos);
void	clear_line(char *buf, int *len, int *pos);
int		is_word_symbol(char c);
int		move_next_word_pos(char *buf, int len, int pos);
int		move_back_word_pos(char *buf, int len, int pos);
t_history	*create_history(void);
t_line		*create_line(void);
void		check_line_reallocation(t_line *line);
void		check_history_reallocation(t_history *hst);
int			error_handling(int error);
int			history_handling(t_history *hst, t_line *line, t_uchar c);
void		history_check_last(t_history *hst, t_line *line);
void		init_line(t_line *line);
int			check_modes(char *buf, int *len, int *pos, t_uchar c);
void		print_prompt(void);

int		g_mode;
int		g_prev_symbol;
time_t	g_time;

#endif
