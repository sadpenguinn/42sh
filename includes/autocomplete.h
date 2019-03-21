/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:01:24 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/21 14:00:51 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTOCOMPLETE_H
# define AUTOCOMPLETE_H

# include "readline.h"
# include "extention.h"
# include "libft.h"
# include "shell.h"
# include "execute.h"
# include "parser.h"
# include "get_next_line.h"
# include "conditions.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/stat.h>

/*
** support of flags_autocomlite not realized yes, so it's reason, why
** flags == other
*/

# define UL							unsigned long
# define ERROR_AUTOCOMLITE			0
# define ENV_AUTOCOMLITE			1
# define FLAGS_AUTOCOMLITE			2
# define OTHER_AUTOCOMLITE			3
# define ONLY_FI_DIR_AUTOCOMLITE	4
# define ONLY_FI_AUTOCOMPLITE		5
# define ONLY_DIR_AUTOCOMPLETE		6
# define ONLY_EXEC_PROGS			7

# define PATH_TO_FLAGS_DB			"/srcs/autocomplete/data_base/"

extern char		*g_built_in_lists[];
extern char		g_path_to_database[999];

char			**autocomplete(t_line *line_info, size_t pos);
char			*atcml_get_pattern(char *buf, size_t pos);
char			*atcml_get_rel_dir(char *buf, size_t pos);
int				check_env_a_case(char c, char cb, size_t pos);
int				check_oth_a_case(t_line *line_info, size_t pos);
int				get_autocomplite_type(t_line *line_info,
				size_t pos, size_t *pos_start);
char			*ft_strendchr(char *str, char c);
char			*dir_or_file_case(char *str, char *word);
char			*cut_begin_in_unique_suggetion(char *str, char *word, int type);
size_t			get_mas_env_autocompl_len(char *str);
char			**get_mas_env_autocompl(char *str);
char			**tab_cat(char **to_str, char **from_str);
size_t			autocomplite_hash_find_len(t_hash *hash, char *str);
char			**autocomplite_hash_find(t_hash *hash, char *str, char **res,
				int *c);
size_t			get_autocomplite_built_in_mas_len(char *str);
char			**get_autocomplite_built_in_mas(char *str, char **res, int *c);
size_t			get_autocomplite_functions_mas_len(char *str);
char			**get_autocomplite_functions_mas(char *str, char **res, int *c);
size_t			get_autocomplite_files_dir_len(char *str);
char			**get_autocomplite_files_dir_mas(char *str, char **res, int *c);
char			**get_mas_other_autocompile(char *str);
char			**get_mas_of_suggetions(char *word, int type);
char			**sugg_delete_repeats(char **str);
int				sugg_check_repeats_in_all_mass(char **str, size_t pos, char *c);
char			**sugg_free_and_set_one(char **str, size_t pos);
char			**sugg_get_common_repeat(char **str, char *sugg_word, int type);
size_t			get_autocomplite_flags_len(char *str, int *fd_to_free);
char			**get_autocomplite_flags_mas(char *str, char **res, size_t *c);
void			init_autocomplete(void);
char			*autocomplete_get_real_programm_name(char *str);
char			*get_autocomplite_real_flags(char *str, int strdup);
char			*cut_begin_ius_flags(char *str, char *word);
char			*autocomplete_beautifulizing_string(char *str, size_t max);
char			**autocomplete_beautifulizing_mas(char **str);
char			*autocomplite_backsl_str(char *str);
char			**autocomplite_get_backslashing(char **str);
char			**get_only_fi_di_autocompile(char *str);
int				check_onlyfd_case(t_line *line_info, size_t pos);
int				check_only_flags_case(char *str, size_t pos);
size_t			get_position_in_flags_case(char *str, size_t pos);
int				check_only_files_case_type(char *str);
int				check_only_dir_case_type(char *str);
char			**get_only_fi_autocompile(char *str);
char			**get_only_fi_autocompile_len(char *str, int *count);
char			**get_only_dir_autocompile(char *str);
char			**processing_hidden_files(char **res, char *str);
int				get_type_fd_flags_other(t_line *line_info, size_t pos,
															size_t *pos_start);
char			*get_real_prog_name_files_dir(char *str, size_t i);
char			**get_flags_autocompile(char *str);
int				check_only_exec_case(char *str, size_t pos);
char			**get_only_exec_fi_mas(char *str);

void			printmas_delete(char **str);

#endif
