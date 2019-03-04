#include "readline.h"

int	are_default_shortcuts(t_matrix *matrix, t_uchar c)
{
	if (c == CTRL_B || c == LEFT)
		return (move_cursor_left(matrix));
	if (c == CTRL_F || c == RIGHT)
		return (move_cursor_right(matrix));
	if (c == HOME1 || c == HOME2)
		return (move_cursor_home(matrix));
	if (c == END1 || c == END2)
		return (move_cursor_end(matrix));
	if (c == DEL)
		return (del(matrix));
	if (c == CTRL_P)
		return (move_history_prev());
	if (c == CTRL_N)
		return (move_history_next());
	if (c == UP)
		return (move_cursor_up(matrix));
	if (c == DOWN)
		return (move_cursor_down(matrix));
	return (0);
}
