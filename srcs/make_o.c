/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:34:15 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/27 13:51:38 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_prec_o(t_struct *elem, char *s)
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

int	ft_gab_o(t_struct *elem)
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

int	ft_has_flags_o(t_struct *elem, char *s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] && j == 0)
	{
		if (s[i] != '0')
			j++;
		i++;
	}
	if (elem->has_flag == 1 && elem->flags->diese == 1)
	{
		if (j == 0 && elem->prec_null == 0 && elem->prec == 0)
			return (1);
		ft_putchar('0');
	}
	return (1);
}

int	make_o(t_struct *elem, char *s, int todo_flag)
{
	if (elem->neg == 0 && elem->has_flag == 1 && elem->flags->diese == 1)
	{
		if (elem->prec > (int)ft_strlen(s))
			elem->prec--;
		else
			elem->todo_gab--;
		elem->ret++;
		todo_flag = 1;
	}
	if (elem->has_flag && elem->flags->moins == 1)
	{
		ft_has_flags_o(elem, s);
		ft_prec_o(elem, s);
		ft_gab_o(elem);
	}
	else
	{
		ft_gab_o(elem);
		ft_has_flags_o(elem, s);
		ft_prec_o(elem, s);
	}
	return (1);
}
