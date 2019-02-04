/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:21:09 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/04 18:10:17 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int			is_term(char c)
{
	if (c == ';')
		return (1);
	return (0);
}

char				*trim_quotes(char *str)
{
	char	*dest;
	char	lastquote;
	int		flag;
	int		len;
	int		cls;
	int		i;
	int		k;

	if (!(len = ft_strlen(str)))
		return (ft_strnew(0));
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	k = 0;
	cls = 0;
	flag = 0;
	lastquote = 0;
	while (i < len)
	{
		if (flag && lastquote && cls && (is_delim(str[i]) || str[i] == '\'' || str[i] == '\"') && str[i + 1] == 'e' && str[i - 1] != '\\')
		{
			i++;
			cls = 0;
			continue ;
		}
		else if (flag && lastquote && cls && (is_delim(str[i]) || str[i] == '\'' || str[i] == '\"') && str[i - 1] != '\\')
		{
			dest[k++] = lastquote;
			lastquote = 0;
			flag = 0;
			cls = 0;
		}
		if ((str[i] == '\'' || str[i] == '\"') && !lastquote && str[i - 1] != '\\')
		{
			lastquote = str[i];
			dest[k++] = lastquote;
			cls = 1;
		}
		else if (str[i] == lastquote && cls && (is_delim(str[i + 1]) || is_term(str[i + 1]) || str[i + 1] == '\0'))
		{
			dest[k++] = lastquote;
			lastquote = 0;
			cls = 0;
		}
		else if (str[i] == lastquote && cls && (str[i + 1] == '\'' || str[i + 1] == '\"') && str[i - 1] != '\\')
			cls = 0;
		else if (str[i] == lastquote && !cls && (is_delim(str[i + 1]) || str[i + 1] == '\0' || str[i + 1] == '\'' || str[i + 1] == '\"') && str[i - 1] != '\\')
			cls = 1;
		else if (str[i] == lastquote && cls && str[i - 1] != '\\')
			flag = 1;
		else
			dest[k++] = str[i];
		i++;
	}
	if (flag && lastquote)
		dest[k++] = lastquote;
	dest[k] = '\0';
	return (dest);
}
