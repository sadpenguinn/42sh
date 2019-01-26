#include "lexer.h"

typedef struct			s_astree
{
	int				type;
	char			*content;
	struct s_astree	*left;
	struct s_astree	*right;
}						t_astree;

extern unsigned int		g_curtok;
extern void				*g_tokens;

/*
** &&	AND_IF
** ||	OR_IF
** ;;	DSEMI
**
** <	LESS
** >	GREAT
** <&	LESSAND
** >&	GREATAND
** <<	DLESS
** >>	DGREAT
** <>	LESSGREAT
** >|	CLOBBER
** <<-	DLESSDASH
**
** W=W	ASSIGMENT_WORD
**
*/

# define SHIFT			100

# define WORD			77
# define NUMBER			66

# define AND_IF			SHIFT + 1
# define OR_IF			SHIFT + 2
# define DSEMI			SHIFT + 3

# define LESS			SHIFT + 4
# define GREAT			SHIFT + 5
# define LESSAND		SHIFT + 6
# define GREATAND		SHIFT + 7
# define DLESS			SHIFT + 8
# define DGREAT			SHIFT + 9
# define LESSGREAT		SHIFT + 10
# define CLOBBER		SHIFT + 11
# define DLESSDASH		SHIFT + 12

# define ASSIGMENT_WORD	SHIFT + 13

t_astree	*simple_command(void);
t_astree	*cmd_name(void);
t_astree	*cmd_word(void);
t_astree	*cmd_prefix(void);
t_astree	*cmd_suffix(void);
t_astree	*io_redirect(void);
t_astree	*io_file(void);
t_astree	*filename(void);
t_astree	*io_here(void);
t_astree	*here_end(void);
