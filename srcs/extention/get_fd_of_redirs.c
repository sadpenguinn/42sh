/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fd_of_redirs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 22:30:31 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/14 22:55:33 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extention.h"

char		*extention_get_just_command(char *str)
{
	int i;
	int dump;

	i = 1;
	while (str[i] && (str[i] == '(' || str[i] == ' '))
		i++;
	dump = i;
	while (str[i] && str[i] != ')')
		i++;
	return (ft_strndup(&str[dump], i - dump));
}

int			check_process_substitution_expand(char *str)
{
	int		i;
	int		brackets;

	brackets = 1;
	if ((str[0] != '<' && str[0] != '>') || str[1] != '(')
		return (0);
	i = 2;
	while (str[i] && brackets)
	{
		if (str[i] == ')')
			brackets--;
		else if (str[i] == '(')
			brackets++;
		i++;
	}
	return ((brackets) ? 0 : 1);
}

char		*get_small_redir(char *str)
{
	char	*tmp_c;
	char	*tmp_num;
	char	*res;

	tmp_c = extention_get_just_command(str);
	tmp_num = ft_itoa(get_fdnumber_of_substitution(tmp_c, 0));
	res = ft_strjoin("/dev/fd/", tmp_num, 0);
	free(tmp_c);
	free(tmp_num);
	return (res);
}

char		*get_grade_redir(char *str)
{
	char	*tmp_c;
	char	*tmp_num;
	char	*res;

	tmp_c = extention_get_just_command(str);
	tmp_num = ft_itoa(get_fdnumber_of_substitution(tmp_c, 1));
	res = ft_strjoin("/dev/fd/", tmp_num, 0);
	free(tmp_c);
	free(tmp_num);
	return (res);
}
