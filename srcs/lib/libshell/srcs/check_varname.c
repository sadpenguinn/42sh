/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_of_variable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 00:50:03 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/09 16:36:39 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int check_varname(const char *str)
{
	int i;

	i = 0;
	if (!str || !str[0] || (str[0] <= '9' && str[0] >= '0') || str[0] == '=')
		return (0);
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' &&
												str[i] <= 'Z') || (str[i] == '_') ||
		   (str[i] >= 'a' && str[i] <= 'z'))
		i++;
	if (!str[i])
		return (1);
	return (0);
}
