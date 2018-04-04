/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   todo_gab_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:35:13 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/27 13:55:53 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		todo_gab_p(t_struct *elem, char *s)
{
	int len;

	len = (int)ft_strlen(s);
	if (ft_atoi(s) == 0)
	{
		if (elem->prec_null == 1 && elem->gab > 0)
			elem->todo_gab++;
		else if (elem->prec_null == 0 && elem->prec < elem->gab - 2)
			elem->todo_gab = elem->todo_gab - elem->prec - 2;
		else
			elem->todo_gab = 0;
	}
	else
	{
		if (len > elem->prec)
			elem->todo_gab = elem->gab - len;
		else
			elem->todo_gab = elem->gab - elem->prec;
	}
}
