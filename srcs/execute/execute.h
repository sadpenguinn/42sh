/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 22:09:39 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/02/14 18:27:28 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "../parser/parser.h"
# include <pthread.h>
# include <unistd.h>
# include <fcntl.h>
# define T_EXECUTE 1
# define T_FILE 2

typedef struct			s_table_redir
{
	int					type;
	int					fd;
	char				*content;
}						t_table_exec;

char					*get_extension(char *str);
int						check_bin_in_path(char *str);
void					switcher_in_processing(t_table_exec *exec);
void					configure_and_run_execv(char **env, char **argv,
												t_table_exec **exec);
void					print_tables(char **env, char **argv,
										t_table_exec **exec);
#endif
