/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <sitlcead@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:12:17 by sitlcead          #+#    #+#             */
/*   Updated: 2019/02/22 09:08:15 by sitlcead         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_H
# define READLINE_H

# define CSI "\e["
# define COLOR_DEFAULT "\e[0m"
# define CURSOR_MOVE_LINE_START "\e[1G"
# define CURSOR_CLEAR_TO_END_SCREEN "\e[0J"
# define CURSOR_CLEAR_TO_START_SCREEN "\e[1J"
# define CURSOR_CLEAR_SCREEN "\ec"

# define TEXT_COLOR_BLACK "\e[30m"
# define TEXT_COLOR_RED "\e[31m"
# define TEXT_COLOR_GREEN "\e[32m"
# define TEXT_COLOR_YELLOW "\e[33m"
# define TEXT_COLOR_BLUE "\e[34m"
# define TEXT_COLOR_MAGENTA "\e[35m"
# define TEXT_COLOR_CYAN "\e[36m"
# define TEXT_COLOR_WHITE "\e[37m"

# define TEXT_BOLD "\e[1m"

# include <sys/ioctl.h>
# include <string.h>

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

enum	vi_modes
{
	NORMAL_MODE = 1, VISUAL_MODE = 2, INSERT_MODE = 3
};

enum	allocation_params
{
	HISTORY_SIZE = 10, BUF_DEFAULT_SIZE = 5, RATIO = 2, MATRIX_DEFAULT_SIZE = 10
};

# define CTRL_V 026
# define CTRL_D 004

typedef unsigned long long int t_uchar;

typedef struct s_cursor
{
	int row;
	int col;
} t_cursor;

typedef struct  s_line
{
	int size;
	int len;
	int symbols;
	char *buf;
}               t_line;

typedef struct s_matrix
{
	int		size;
	int len;
	t_line **lines;
	t_cursor *cursor;
	int last_offset;
	int left_limit;
	int right_limit;
} t_matrix;

int g_mode;
struct winsize g_w;

char *readline(void);
void    clear_screen_down(void);
void    save_cursor(void);
void    restore_cursor(void);
void        print_prompt(void);

t_matrix *init_matrix(void);
t_line *init_line(void);
void	matrix_create_line(t_matrix *matrix, int row);

int check_next_symbol(t_matrix *matrix);
int check_utf(t_matrix *matrix, t_uchar c);
t_uchar	get_next_symbol(size_t size);
int get_utf_offset(unsigned char c);

void	get_term_params(struct winsize	*w);

void    comb_offset(t_uchar c);
void    add_cursor_offset(int offset);
void add_lines(t_matrix *matrix);
int     readline_mode(t_matrix *matrix, char *str, t_uchar c);
int check_esc_code(t_matrix *matrix);
int check_modes(t_matrix *matrix, t_uchar c);
int print_autocomplete(t_matrix *matrix);

void    matrix_string_insert(t_matrix *matrix, const char *str, int size);
int	make_string_from_symbol(char *str, t_uchar c);

void    line_resize(t_line *line, int new_size, int old_size);
void    matrix_resize(t_matrix *matrix, int new_size, int old_size);

int move_cursor_left(t_matrix *matrix);
int move_cursor_right(t_matrix *matrix);
int move_cursor_up(t_matrix *matrix);
int move_cursor_down(t_matrix *matrix);
int move_cursor_home(t_matrix *matrix);
int move_cursor_end(t_matrix *matrix);

int get_line_prompt_len(int max);

int print_default(t_matrix *matrix);

int count_string_symbols(char *buf, int n);

void	matrix_string_delete(t_matrix *matrix, int size);

int		del(t_matrix *matrix);
int		back_space(t_matrix *matrix);

void	matrix_erase_line(t_matrix *matrix, int row);

void	line_free(t_line *line);
void	line_del(t_line **line);
void	matrix_free(t_matrix *matrix);
void	matrix_del(t_matrix **matrix);

#endif
