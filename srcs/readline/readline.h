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
# define COLOR_PROMPT "\e[1m\e[34m"
# define COLOR_DEFAULT "\e[0m"
# define CURSOR_MOVE_LINE_START "\e[1G"
# define CURSOR_CLEAR_TO_END_SCREEN "\e[0J"
# define CURSOR_CLEAR_TO_START_SCREEN "\e[1J"
# define CURSOR_CLEAR_SCREEN "\ec"

enum	keys
{
	UP = 0x415b1b, DOWN = 0x425b1b, CTRL_P = 0x10, CTRL_N = 0xe,
	RIGHT = 0x435b1b, LEFT = 0x445b1b, CTRL_F = 0x6, CTRL_B = 0x2,
	BS = 0x7f, DEL = 0x7e335b1b,
	HOME1 = 0x485b1b, END1 = 0x465b1b, HOME2 = 0x7e315b1b, END2 = 0x7e345b1b,
	ESC = 0x1b
};

enum	editing_modes
{
	VI = 1, READLINE = 2
};

enum	modes
{
	NORMAL_MODE = 1, VISUAL_MODE = 2, INSERT_MODE = 4
};

enum	allocation_params
{
	HISTORY_SIZE = 10, LINE_SIZE = 1024, RATIO = 2
};

# define CTRL_V 026
# define CTRL_D 004

typedef long long int t_uchar;

#define MATRIX_DEFAULT 10
#define BUF_DEFAULT 5

typedef struct s_cursor
{
	int row;
	int col;
} t_cursor;

typedef struct  s_line
{
	int size;
	int len;
	int cnt;
	char *buf;
}               t_line;

typedef struct s_matrix
{
	int size;
	int len;
	t_line **line;
	t_cursor *cursor;
} t_matrix;

int     ft_readline(t_matrix *);
t_uchar	get_next_symbol(void);
void    clear_screen_down(void);
void    save_cursor(void);
void    restore_cursor(void);
void        print_prompt(void);

t_line *init_line(void);
t_matrix *init_matrix(void);

#endif
