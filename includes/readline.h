/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <sitlcead@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:12:17 by sitlcead          #+#    #+#             */
/*   Updated: 2019/03/03 21:39:06 by sitlcead         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_H
# define READLINE_H

# define CSI "\e["
# define COLOR_DEFAULT "\e[0m"
# define DEFAULT_TERM_COLORS "\e[0m\e[39;49m"
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
# define TEXT_REVERSE_VIDEO "\e[7m"
# define TURN_ON_CURSOR "\e[?25h"
# define TURN_OF_CURSOR "\e[?25l"

# define TEXT_BOLD "\e[1m"

# define SHELL_NAME "[42sh]"

# define SHORTCUT_ARRAY_SIZE 10

# define HISTORY_FILE ".42sh_history"

# include <sys/ioctl.h>
# include <string.h>

enum	e_keys
{
	UP = 0x415b1b, DOWN = 0x425b1b, CTRL_P = 0x10, CTRL_N = 0xe,
	RIGHT = 0x435b1b, LEFT = 0x445b1b, CTRL_F = 0x6, CTRL_B = 0x2,
	BS = 0x7f, DEL = 0x7e335b1b,
	HOME1 = 0x485b1b, END1 = 0x465b1b, HOME2 = 0x7e315b1b, END2 = 0x7e345b1b,
	ESC = 0x1b
};

enum	e_editing_modes
{
	VI = 1, READLINE = 2
};

enum	e_vi_mode_editing_modes
{
	INSERT_MODE = 0, NORMAL_MODE = 1, VISUAL_MODE = 2, REPLACE_MODE = 3
};

enum	e_allocation_params
{
	HISTORY_DEFAULT_SIZE = 10, BUF_DEFAULT_SIZE = 5, RATIO = 2,
	MATRIX_DEFAULT_SIZE = 10, ARRAY_DEFAULT_SIZE = 10, READ_SIZE = 100
};

# define CTRL_V 026
# define CTRL_D 004

typedef	unsigned long long int	t_uchar;

typedef	struct	s_array
{
	char		*buf;
	size_t		len;
	size_t		size;
}				t_array;

typedef	struct	s_cursor
{
	int			row;
	int			col;
}				t_cursor;

typedef	struct	s_string
{
	size_t		len;
	char		*buf;
}				t_string;

typedef	struct	s_line
{
	int			size;
	int			len;
	int			symbols;
	char		*buf;
}				t_line;

typedef	struct	s_matrix
{
	int			size;
	int			len;
	t_line		**lines;
	t_cursor	*cursor;
	int			left_limit;
	int			right_limit;
	int			single_quotes;
	int			double_quotes;
	t_string	*str;
}				t_matrix;

typedef struct	s_history
{
	int			size;
	int			len;
	int			cur;
	int			last_offset;
	t_matrix	**matrix;
	t_matrix	*cur_matrix;
	t_string	*str;
	t_line		*line_search;
}				t_history;

t_history		*g_history;
int				g_mode;
int				g_search_mode;
int				g_vi_mode;
struct winsize	g_w;
t_uchar			g_shortcuts[SHORTCUT_ARRAY_SIZE];
t_uchar			g_shortcut_nbr;

t_string		*readline(void);

void			ft_puts(char *buf);

t_matrix		*matrix_init(void);
t_line			*line_init(void);
t_string		*string_init(void);
t_cursor		*cursor_init(void);

t_matrix		*matrix_dup(t_matrix *src);
t_line			*line_dup(t_line *src);
t_cursor		*cursor_dup(t_cursor *src);
t_string		*string_dup(t_string *src);

void			string_fill(t_string *str, char *buf, int len);

void			matrix_create_line(t_matrix *matrix, int row);
void			matrix_erase_line(t_matrix *matrix, int row);

int				check_next_symbol(void);
t_uchar			get_next_symbol(size_t size);

void			get_term_params(struct winsize	*w);

int				add_shortcut(t_uchar c);

void			add_cursor_offset(void);
void			reset_last_offset(void);

int				readline_mode(t_matrix *matrix, t_uchar c);
int				vi_mode(t_matrix *matrix, t_uchar c);
int				modes_handling(t_matrix *matrix, t_uchar c);
int				esc_code_handling(t_uchar c);

int				normal_mode(t_matrix *matrix, t_uchar c);
int				insert_mode(t_matrix *matrix, t_uchar c);
int				replace_mode(t_matrix *matrix, t_uchar c);

void			paste_before(t_matrix *matrix);
void			paste_after(t_matrix *matrix);

int				del_begin_word(t_matrix *matrix);
int				del_next_word(t_matrix *matrix);
int				del_end_word(t_matrix *matrix);
int				del_end(t_matrix *matrix);
int				del_home(t_matrix *matrix);
int				del_string(t_matrix *matrix);
int				del_begin_alnum(t_matrix *matrix);
int				del_next_alnum(t_matrix *matrix);
int				del_end_alnum(t_matrix *matrix);

int				yank_begin_word(t_matrix *matrix);
int				yank_next_word(t_matrix *matrix);
int				yank_end_word(t_matrix *matrix);
int				yank_end(t_matrix *matrix);
int				yank_home(t_matrix *matrix);
int				yank_string(t_matrix *matrix);
int				yank_begin_alnum(t_matrix *matrix);
int 			yank_next_alnum(t_matrix *matrix);
int				yank_end_alnum(t_matrix *matrix);

t_cursor		matrix_string_insert(t_matrix *matrix, t_cursor pos,
		const char *str, int size);
void			matrix_string_delete(t_cursor left, t_cursor right);
void			matrix_string_yank(t_matrix *matrix, int row, int col);

void			line_resize(t_line *line, int new_size, int old_size);
void			matrix_resize(t_matrix *matrix, int new_size, int old_size);

int				move_cursor_left(t_matrix *matrix);
int				move_cursor_right(t_matrix *matrix);
int				move_cursor_up(t_matrix *matrix);
int				move_cursor_down(t_matrix *matrix);
int				move_cursor_home(t_matrix *matrix);
int				move_cursor_end(t_matrix *matrix);
int				move_cursor_next_word(t_matrix *matrix);
int				move_cursor_begin_word(t_matrix *matrix);
int				move_cursor_end_word(t_matrix *matrix);
int				move_cursor_begin(t_matrix *matrix);
int				move_cursor_next_alnum(t_matrix *matrix);
int				move_cursor_end_alnum(t_matrix *matrix);
int				move_cursor_begin_alnum(t_matrix *matrix);

int				del(t_matrix *matrix);
int				back_space(t_matrix *matrix);

int				print_default(t_matrix *matrix);
int				print_lines(t_matrix *matrix);
int				print_autocomplete(t_matrix *matrix);

void			print_prompt(void);

void			line_free(t_line *line);
void			cursor_free(t_cursor *cursor);
void			string_free(t_string *str);
void			matrix_free(t_matrix *matrix);
void			history_free(t_history *history);

void			line_del(t_line **line);
void			string_del(t_string **str);
void			matrix_del(t_matrix **matrix);
void			history_del(t_history **history);

int				get_utf_offset_left(char *str, int pos);
int				get_utf_offset_right(unsigned char c);

int				count_string_symbols(char *buf, int n);
int				count_string_cols(char *buf, int symbols);

int				get_lines_prompt_len(int max);
int				get_lines_offset(int len);

int				newline_handling(t_matrix *matrix);

void			add_lines_prompt_style(void);
void			add_cur_line_prompt_style(void);
void			add_prompt_style(void);
void			add_shell_name_style(void);

int				symbol_to_string(t_matrix *matrix, t_uchar c, char *str);

int				set_matrix_limits(t_matrix *matrix);

void			matrix_to_string(t_matrix *matrix, t_string *str);

void			add_cursor_text(t_matrix *matrix);
void			add_lines_text(t_matrix *matrix);
void			add_text(t_matrix *matrix, int row, int col);

void			add_line_prefix(t_matrix *matrix, int cur_row);

int				autocomplete_file_dir(t_matrix *matrix);

int				matrix_cmp(t_matrix *matrix1, t_matrix *matrix2);

int				move_history_prev(void);
int				move_history_next(void);

void			array_add(const char *str, size_t len);
char			*array_to_string(void);
void			array_flush(void);

int				get_cursor_pos_home(t_matrix *matrix);
int				get_cursor_pos_begin(t_matrix *matrix);
int				get_cursor_pos_end(t_matrix *matrix);
int				get_cursor_pos_left(t_matrix *matrix);
int				get_cursor_pos_right(t_matrix *matrix);
int				get_cursor_pos_next_word(t_matrix *matrix);
int				get_cursor_pos_begin_word(t_matrix *matrix);
int				get_cursor_pos_end_word(t_matrix *matrix);
int				get_cursor_pos_next_alnum(t_matrix *matrix);
int				get_cursor_pos_begin_alnum(t_matrix *matrix);
int				get_cursor_pos_end_alnum(t_matrix *matrix);

int				are_default_shortcuts(t_matrix *matrix, t_uchar c);

void			buffer_add(const char *str, int size);
void			buffer_free(void);
char			*get_buffer_content(void);
int				get_buffer_len(void);

int 			lex_check_bash_word(const char *str, size_t len);

int				history_save_elem(void);
void	history_resize(t_history *history);
void		history_fill(void);

#endif
