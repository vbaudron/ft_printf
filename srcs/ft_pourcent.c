/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pourcent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:31:38 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/27 13:25:19 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	has_gab_pourcent(t_struct *elem)
{
	int nb;
	int i;

	nb = 0;
	i = 0;
	if (elem->has_flag == 1 && elem->flags->moins == 1)
	{
		ft_putchar('%');
		nb++;
	}
	while (nb < elem->gab - 1)
	{
		if (elem->has_flag == 1 && elem->flags->moins == 0 &&
			elem->flags->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		nb++;
	}
	if (elem->has_flag == 1 && elem->flags->moins == 1)
		ft_putchar(' ');
	else
		ft_putchar('%');
	return (nb + 1);
}

int	ft_pourcent(const char **format, int i)
{
	int			nb;
	t_struct	*elem;

	nb = 0;
	elem = NULL;
	if ((*format)[i] == '%')
	{
		ft_putchar('%');
		return (1);
	}
	if ((elem = crea_struct(elem, format, i, crea_t_specif())) == NULL)
		return (-1);
	if (elem->gab != -1)
		nb = has_gab_pourcent(elem);
	else if (elem->gab == -1)
	{
		ft_putchar('%');
		nb = 1;
	}
	ft_free_struct(elem);
	return (nb);
}
