/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:34:37 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/27 13:52:51 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_prec_u(t_struct *elem, char *s)
{
	int	len;
	int	i;

	i = 0;
	len = (int)ft_strlen(s);
	while (i + len < elem->prec)
	{
		ft_putchar('0');
		i++;
	}
	if (ft_atoi(s) == 0 && elem->prec_null == 1)
		return (i);
	ft_putstr(s);
	return (i);
}

int	ft_gab_u(t_struct *elem)
{
	int i;

	i = 0;
	if (elem->has_flag && elem->flags->zero == 1 && elem->flags->moins == 0
	&& elem->prec == 0)
	{
		while (i++ < elem->todo_gab)
			ft_putchar('0');
	}
	else
	{
		while (i++ < elem->todo_gab)
			ft_putchar(' ');
	}
	return (i);
}

int	make_u(t_struct *elem, char *s)
{
	if (elem->has_flag && elem->flags->moins == 1)
	{
		ft_prec_u(elem, s);
		ft_gab_u(elem);
	}
	else
	{
		ft_gab_u(elem);
		ft_prec_u(elem, s);
	}
	return (1);
}
