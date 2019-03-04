/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:04:29 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/04 18:41:47 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplite.h"

int     get_autocomplite_type(t_line *line_info, int pos)
{
    if (!pos || line_info->buf[pos] == ' ' || line_info->buf[pos] == ';')
        return (ERROR_AUTOCOMLITE);
    while (pos && line_info->buf[pos] != ' ' && line_info->buf[pos] != ';')
    {
        if (line_info->buf[pos] == '$')
            return (ENV_AUTOCOMLITE);
        else if (line_info->buf[pos] == '/')
            return (DIR_AUTOCOMLITE);
        else if (line_info->buf[pos] == ' ')
            return (EXECUTE_OR_FILE_AUTOCOMLITE);
        pos--;
    }
    printf("Этот тип автодополнения ещё не предусмотрен\n");
    return (ERROR_AUTOCOMLITE);
}

char    **autocomplite(t_line *line_info, int pos)
{
    int type;

    type = get_autocomplite_type(line_info, pos);

}