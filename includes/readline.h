/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <sitlcead@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:12:17 by sitlcead          #+#    #+#             */
/*   Updated: 2019/03/09 13:11:00 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_H
# define READLINE_H

# define CSI "\e["
# define CSI_DEFAULT "\e[0m"

# define DEFAULT_TERM_COLORS "\e[39;49m"
# define DEFAULT_TEXT_COLORS "\e[39m"

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

# define BG_DEFAULT_COLOR "\e[49m"
# define BG_COLOR_BLACK "\e[40m"
# define BG_COLOR_RED "\e[41m"
# define BG_COLOR_GREEN "\e[42m"
# define BG_COLOR_YELLOW "\e[43m"
# define BG_COLOR_BLUE "\e[44m"
# define BG_COLOR_MAGENTA "\e[45m"
# define BG_COLOR_CYAN "\e[46m"
# define BG_COLOR_WHITE "\e[47m"

# define TEXT_REVERSE_VIDEO "\e[7m"

# define TURN_ON_CURSOR "\e[?25h"
# define TURN_OF_CURSOR "\e[?25l"

# define TEXT_BOLD "\e[1m"
# define TEXT_UNBOLD "\e[22m"

# define SHELL_NAME "[42sh]"

# define SHORTCUT_ARRAY_SIZE 10

# define HISTORY_FILE ".42sh_history"

# define SEARCH_PROMPT "search : "

# define SYNTAX_ON 1
# define SYNTAX_OFF 0

# define EVENT_MESSAGE "event not found"

# define TAB_LEN 4

# include <sys/ioctl.h>
# include <string.h>
# include <stdio.h>

enum	e_bang
{
	NO_BANGS = 0, BANG_REPLACED = 1, BANG_ERROR = 2
};

enum	e_act
{
	INSERT = 0, DELETE = 1
};

enum	e_keys
{
	UP = 0x415b1b, DOWN = 0x425b1b, CTRL_P = 0x10, CTRL_N = 0xe,
	RIGHT = 0x435b1b, LEFT = 0x445b1b, CTRL_F = 0x6, CTRL_B = 0x2,
	BS = 0x7f, DEL = 0x7e335b1b,
	HOME1 = 0x485b1b, END1 = 0x465b1b, HOME2 = 0x7e315b1b, END2 = 0x7e345b1b,
	ESC = 0x1b,
	CTRL__ = 31, CTRL_T = 20,
	CTRL_H = 8, CTRL_L = 12,
	CTRL_V = 026, CTRL_R = 022, CTRL_D = 04
};

enum	e_editing_modes
{
	VI = 1, READLINE = 0
};

enum	e_vi_mode_editing_modes
{
	INSERT_MODE = 0, NORMAL_MODE = 1, VISUAL_MODE = 2, REPLACE_MODE = 3
};

enum	e_allocation_params
{
	HISTORY_DEFAULT_SIZE = 10, BUF_DEFAULT_SIZE = 5, RATIO = 2,
	MATRIX_ARRAY_DEFAULT_SIZE = 10, ARRAY_DEFAULT_SIZE = 10, MODIF_ARRAY_DEFAULT_SIZE = 10
};

typedef	unsigned long long int	t_uchar;

typedef	struct	s_array
{
	char		*buf;
	size_t		len;
	size_t		size;
}				t_array;

typedef	struct	s_cursor
{
	size_t		row;
	size_t		col;
}				t_cursor;

typedef	struct	s_string
{
	size_t		len;
	char		*buf;
}				t_string;

typedef	struct	s_line
{
	size_t		size;
	size_t		len;
	size_t		symbols;
	char		*buf;
}				t_line;

typedef	struct	s_action
{
	int			act;
	t_cursor	start;
	t_cursor	end;
	char		*buf;
}				t_action;

typedef	struct	s_modification
{
	size_t		len;
	size_t		size;
	size_t		cur;
	t_action	**actions;
}				t_modification;

typedef	struct	s_matrix
{
	size_t			size;
	size_t			len;
	t_line			**lines;
	t_cursor		*cursor;
	size_t			left_limit;
	size_t			right_limit;
	t_string		*str_history;
	t_cursor		point;
	t_modification	*modif;
}				t_matrix;

typedef struct	s_history
{
	size_t		size;
	size_t		len;
	size_t		cur;
	size_t		last_offset;
	t_matrix	**matrix;
	t_matrix	*last_hst_matrix;
	t_string	*buffer;
	t_line		*search_line;
	int			is_replace;
	t_string	*event;
	char		find_char;
	int			redo_undo;
}				t_history;

extern t_history		*g_history;
extern int				g_mode;
extern int				g_search_mode;
extern int				g_heredoc;
extern int				g_vi_mode;
extern int				g_syntax;
extern struct winsize	g_w;
extern t_uchar			g_shortcuts[SHORTCUT_ARRAY_SIZE];

t_string		*readline(void);
t_string		*heredoc(void);

t_matrix		*matrix_init(void);
t_line			*line_init(void);
t_string		*string_init(void);
t_cursor		*cursor_init(void);
t_modification	*modification_init(void);

t_matrix		*matrix_dup(t_matrix *src);
t_line			*line_dup(t_line *src);
t_cursor		*cursor_dup(t_cursor *src);
t_string		*string_dup(t_string *src);

void			string_fill(t_string *str, char *buf, size_t len);

void			matrix_insert_line(t_matrix *matrix, size_t row);
void			matrix_erase_line(t_matrix *matrix, size_t row);

int				check_next_symbol(void);
t_uchar			get_next_symbol(size_t size);

void			get_term_params(struct winsize	*w);

int				add_shortcut(t_uchar c);

void			add_cursor_offset(void);
void			reset_last_offset(void);

int				readline_mode(t_uchar c);
int				search_mode(t_uchar c);
int				vi_mode(t_uchar c);
int				modes_handling(t_uchar c);
int				esc_code_handling(t_uchar c);

int				normal_mode(t_matrix *matrix, t_uchar c);
int				normal_mode_del(t_matrix *matrix, t_uchar c);
int				normal_mode_yank(t_matrix *matrix, t_uchar c);
int				insert_mode(t_matrix *matrix, t_uchar c);
int				replace_mode(t_matrix *matrix, t_uchar c);
int				visual_mode(t_matrix *matrix, t_uchar c);

int				paste_before(t_matrix *matrix);
int				paste_after(t_matrix *matrix);

int				del_begin_word(t_matrix *matrix);
int				del_next_word(t_matrix *matrix);
int				del_end_word(t_matrix *matrix);
int				del_end(t_matrix *matrix);
int				del_home(t_matrix *matrix);
int				del_begin(t_matrix *matrix);
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
int				yank_next_alnum(t_matrix *matrix);
int				yank_end_alnum(t_matrix *matrix);

t_cursor		matrix_string_insert(t_matrix *matrix, t_cursor pos,
		const char *str, size_t size);
t_cursor		matrix_string_delete(t_cursor left, t_cursor right);
void			matrix_string_yank(t_cursor left, t_cursor right);

size_t			line_string_delete(t_line *line, size_t pos, size_t size);
size_t			line_string_insert(t_line *line, size_t pos,
		const char *str, size_t size);

void			line_resize(t_line *line, size_t new_size, size_t old_size);
void			matrix_resize(t_matrix *matrix, size_t new_size,
		size_t old_size);
void			modification_resize(t_modification *modif, size_t new_size, size_t old_size);

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
int				move_cursor_end_matrix(t_matrix *matrix);
int				move_cursor_next_char(t_matrix *matrix);
int				move_cursor_back_char(t_matrix *matrix);

int				del(t_matrix *matrix);
int				back_space(t_matrix *matrix);

int				print_default(t_matrix *matrix);
int				print_end(t_matrix *matrix);
int				print_search(t_matrix *matrix);
int				print_autocomplete(t_matrix *matrix);
int				print_event_message(void);

void			print_prompt(void);

void			line_free(t_line *line);
void			cursor_free(t_cursor *cursor);
void			string_free(t_string *str);
void			matrix_free(t_matrix *matrix);
void			history_free(t_history *history);
void			action_free(t_action *action);
void			modification_free(t_modification *modif);

void			line_del(t_line **line);
void			string_del(t_string **str);
void			matrix_del(t_matrix **matrix);
void			history_del(t_history **history);

size_t			get_utf_offset_left(const char *str, size_t pos);
size_t			get_utf_offset_right(char c);

size_t			count_string_symbols(const char *buf,
		size_t left_limit, size_t right_limit);
size_t			count_string_cols(const char *buf, size_t symbols);

size_t			get_lines_prompt_len(size_t max);
size_t			get_lines_offset(size_t len);

int				newline_handling(t_matrix *matrix);

void			add_lines_prompt_style(void);
void			add_cur_line_prompt_style(void);
void			add_prompt_style(void);
void			add_shell_name_style(void);

size_t			symbol_to_string(t_uchar c, char *str);

int				set_matrix_limits(t_matrix *matrix);

void			matrix_to_string(t_matrix *matrix, t_string *str);

void			add_cursor_text(t_matrix *matrix);
void			add_lines_text(t_matrix *matrix);
void			add_text(t_matrix *matrix, size_t row, size_t col);
void			add_line(t_line	*line, size_t start, size_t end,
		size_t row);

void			add_line_prefix(t_matrix *matrix, size_t cur_row);

int				matrix_cmp(t_matrix *matrix1, t_matrix *matrix2);

int				move_history_prev(void);
int				move_history_next(void);

void			array_add(const char *str, size_t len);
char			*array_to_string(void);
void			array_flush(void);

size_t			get_cursor_pos_home(t_matrix *matrix);
size_t			get_cursor_pos_begin(t_matrix *matrix);
size_t			get_cursor_pos_end(t_matrix *matrix);
size_t			get_cursor_pos_left(t_matrix *matrix);
size_t			get_cursor_pos_right(t_matrix *matrix);
size_t			get_cursor_pos_next_word(t_matrix *matrix);
size_t			get_cursor_pos_begin_word(t_matrix *matrix);
size_t			get_cursor_pos_end_word(t_matrix *matrix);
size_t			get_cursor_pos_next_alnum(t_matrix *matrix);
size_t			get_cursor_pos_begin_alnum(t_matrix *matrix);
size_t			get_cursor_pos_end_alnum(t_matrix *matrix);
size_t			get_cursor_pos_back_char(t_matrix *matrix);
size_t			get_cursor_pos_next_char(t_matrix *matrix);

size_t			get_space_left_pos(const char *buf, size_t pos);
size_t			get_space_right_pos(const char *buf, size_t pos, size_t len);

void			buffer_add(const char *str, size_t size);
void			buffer_free(void);
char			*get_buffer_content(void);
size_t			get_buffer_len(void);

int				lex_check_bash_word(const char *str, size_t len);

int				history_save(t_string **str);
void			history_resize(t_history *history);
void			history_fill(void);

int				are_quotes(char *buf, size_t len);
int				bang_handling(t_matrix *matrix);

void			set_backslash(char *buf, size_t pos, int *backslash);

int				bang_case(t_line *line, size_t pos);
int				word_case(t_line *line, size_t pos);
int				minus_case(t_line *line, size_t pos);
int				plus_case(t_line *line, size_t pos, int plus_flag);

void			check_swap(t_cursor *start, t_cursor *end);

void			set_points(t_cursor *point1, t_cursor *point2);

void			action_add(t_cursor start, t_cursor end, const char *buf,
		int act);

int				undo(t_matrix *matrix);
int				redo(t_matrix *matrix);

#endif
