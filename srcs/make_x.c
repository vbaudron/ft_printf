/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:34:49 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/27 13:54:42 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_gab_x(t_struct *elem)
{
	int i;

	i = 0;
	if (elem->has_flag && elem->flags->zero == 1 && elem->flags->moins == 0
	&& elem->prec == 0)
	{
		if (elem->has_flag == 1 && elem->flags->zero == 1)
		{
			while (i++ < elem->todo_gab)
				ft_putchar('0');
		}
	}
	else
	{
		while (i++ < elem->todo_gab)
			ft_putchar(' ');
	}
	return (i - elem->neg);
}

int	ft_has_flags_x(t_struct *elem, int todo_flag)
{
	int nb;

	nb = 0;
	if (todo_flag == 1)
	{
		if (elem->specif == 'x')
			ft_putstr("0x");
		else
			ft_putstr("0X");
		nb = 2;
	}
	return (nb);
}

int	print_x(t_struct *elem, char *s)
{
	int i;
	int len;

	i = 0;
	len = (int)ft_strlen(s);
	if (elem->prec_null == 1 && ft_atoi(s) == 0)
		return (1);
	else
	{
		while (i++ < elem->prec - len)
			ft_putchar('0');
		ft_putstr(s);
	}
	return (1);
}

int	make_flags_x_updated(t_struct *elem)
{
	elem->todo_gab = elem->todo_gab - 2;
	elem->ret = elem->ret + 2;
	return (1);
}

int	make_x(t_struct *elem, char *s, int todo_flag)
{
	if (elem->gab > 0 && elem->prec_null == 1 && ft_atoi(s) == 0)
		elem->todo_gab++;
	if (elem->has_flag == 1 && elem->flags->diese == 1 && ft_atoi(s) != 0)
		todo_flag = make_flags_x_updated(elem);
	if (elem->has_flag && elem->flags->moins == 1)
	{
		ft_has_flags_x(elem, todo_flag);
		print_x(elem, s);
		ft_gab_x(elem);
	}
	else if (todo_flag == 1 && elem->flags->zero == 1)
	{
		ft_has_flags_x(elem, todo_flag);
		ft_gab_x(elem);
		print_x(elem, s);
	}
	else
	{
		ft_gab_x(elem);
		ft_has_flags_x(elem, todo_flag);
		print_x(elem, s);
	}
	return (1);
}
