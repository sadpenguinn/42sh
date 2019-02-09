/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 20:53:52 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/09 21:02:01 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	CPLST - ComPound LiST
**
**        IF
**       /  \
**  CPLST    CPLST
**
**        IF
**       /  \
**  CPLST    ELSE
**          /    \
**     CPLST      CPLST
**
**        IF
**       /  \
**  CPLST    ELSE
**          /    \
**     CPLST      IF
**               /  \
**          CPLST    CPLST
**
**        IF
**       /  \
**  CPLST    ELIF
**          /    \
**     CPLST      IF
**               /  \
**          CPLST    CPLST
*/
