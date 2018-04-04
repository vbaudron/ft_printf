/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:34:04 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/27 13:50:57 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_prec_d(t_struct *elem, char *s)
{
	int	len;
	int	i;

	i = 0;
	len = (int)ft_strlen(s);
	if (elem->neg == 1 && elem->done_neg == 0)
	{
		ft_putchar('-');
		elem->done_neg = 1;
	}
	while (i + len - elem->neg < elem->prec)
	{
		ft_putchar('0');
		i++;
	}
	if (ft_atoi(s) == 0 && elem->prec_null == 1)
		return (i);
	if (elem->neg == 1)
		ft_putstr_i(s, 1);
	else
		ft_putstr(s);
	return (i);
}

int	ft_gab_d(t_struct *elem)
{
	int i;

	i = 0;
	if (elem->has_flag && elem->flags->zero == 1 && elem->flags->moins == 0
	&& elem->prec == 0)
	{
		if (elem->neg == 1 && elem->done_neg == 0)
		{
			ft_putchar('-');
			elem->done_neg = 1;
		}
		while (i++ < elem->todo_gab)
			ft_putchar('0');
	}
	else
	{
		while (i++ < elem->todo_gab)
			ft_putchar(' ');
		if (elem->neg == 1 && elem->done_neg == 0)
		{
			ft_putchar('-');
			elem->done_neg = 1;
		}
	}
	return (i - elem->neg);
}

int	ft_has_flags_d(t_struct *elem)
{
	int nb;

	nb = 0;
	if (elem->neg == 0 && elem->has_flag == 1 && elem->flags->plus == 1)
	{
		ft_putchar('+');
		nb++;
	}
	if (elem->neg == 0 && elem->has_flag == 1 && elem->flags->plus != 1 &&
	elem->flags->space == 1)
	{
		ft_putchar(' ');
		nb++;
	}
	return (nb);
}

int	make_flags_updated(t_struct *elem)
{
	elem->todo_gab--;
	elem->ret++;
	return (1);
}

int	make_d(t_struct *elem, char *s, int todo_flag)
{
	if (elem->neg == 0 && elem->has_flag == 1 &&
	(elem->flags->plus == 1 || elem->flags->space == 1))
		todo_flag = make_flags_updated(elem);
	if (elem->has_flag && elem->flags->moins == 1)
	{
		ft_has_flags_d(elem);
		ft_prec_d(elem, s);
		ft_gab_d(elem);
	}
	else if (elem->todo_gab > 0 && todo_flag == 1 && elem->flags->zero != 1)
	{
		ft_gab_d(elem);
		ft_has_flags_d(elem);
		ft_prec_d(elem, s);
	}
	else
	{
		ft_has_flags_d(elem);
		ft_gab_d(elem);
		ft_prec_d(elem, s);
	}
	return (1);
}
