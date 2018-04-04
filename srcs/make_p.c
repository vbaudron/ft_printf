/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:34:28 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/27 13:52:24 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_gab_p(t_struct *elem)
{
	int i;

	i = 0;
	if (elem->has_flag && elem->flags->zero == 1 && elem->flags->moins == 0
	&& elem->prec == 0)
	{
		if (elem->has_flag == 1 && elem->flags-> zero == 1)
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
	return (i);
}

void	ft_has_prec_p(t_struct *elem, char *s)
{
	int i;
	int len;

	i = 0;
	len = (int)ft_strlen(s);
	while (elem->prec > len + i)
	{
		ft_putchar('0');
		i++;
	}
}

int		print_p(t_struct *elem, char *s)
{
	int i;
	int len;

	i = 0;
	len = (int)ft_strlen(s);
	if (elem->prec_null == 1 && ft_atoi(s) == 0)
		return (1);
	else
		ft_putstr(s);
	return (1);
}

int		make_p(t_struct *elem, char *s)
{
	if (elem->todo_gab > 2)
		elem->todo_gab -= 2;
	else
		elem->todo_gab = 0;
	if (elem->has_flag && elem->flags->moins == 1)
	{
		ft_putstr("0x");
		ft_has_prec_p(elem, s);
		print_p(elem, s);
		ft_gab_p(elem);
	}
	else
	{
		ft_gab_p(elem);
		ft_putstr("0x");
		ft_has_prec_p(elem, s);
		print_p(elem, s);
	}
	elem->ret += 2;
	return (1);
}
