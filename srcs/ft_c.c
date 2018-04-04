/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:30:16 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/27 12:12:18 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		has_gab_c(t_struct *elem)
{
	int	j;

	j = 0;
	while (j++ < elem->todo_gab)
	{
		if (elem->has_flag == 1 && elem->flags->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
	}
	return (j);
}

int		ft_c(va_list args, const char **format, int i)
{
	int			c;
	t_struct	*elem;
	int			nb;

	elem = NULL;
	nb = 0;
	c = va_arg(args, int);
	if ((elem = crea_struct(elem, format, i, crea_t_specif())) == NULL)
		return (-1);
	if ((elem->todo_gab = elem->gab - 1) <= 0)
		elem->todo_gab = 0;
	if (elem->has_flag && elem->flags->moins == 1)
	{
		ft_putchar(c);
		has_gab_c(elem);
	}
	else
	{
		has_gab_c(elem);
		ft_putchar(c);
	}
	nb = elem->todo_gab + 1;
	ft_free_struct(elem);
	return (nb);
}
