/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:25:49 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/27 13:27:23 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		has_gab_s(t_struct *elem)
{
	int	j;

	j = 0;
	while (j++ < elem->todo_gab)
	{
		if (elem->has_flag && elem->flags->zero == 1 && elem->flags->moins == 0)
			ft_putchar('0');
		else
			ft_putchar(' ');
	}
	return (j);
}

char	*has_prec_s(t_struct *elem, char *s)
{
	int		i;
	char	*save;

	i = 0;
	save = NULL;
	if (elem->prec > 0 || elem->prec_null == 1)
	{
		save = ft_strnew(elem->prec + 1);
		while (i < elem->prec)
		{
			save[i] = s[i];
			i++;
		}
		return (save);
	}
	return (s);
}

void	make_s(t_struct *elem, char *s)
{
	if (elem->has_flag && elem->flags->moins == 1)
	{
		ft_putstr(s);
		has_gab_s(elem);
	}
	else
	{
		has_gab_s(elem);
		ft_putstr(s);
	}
}

int		ft_s(va_list args, const char **format, int i)
{
	char		*s;
	int			nb;
	t_struct	*elem;

	nb = 0;
	elem = NULL;
	s = va_arg(args, char*);
	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	if ((elem = crea_struct(elem, format, i, crea_t_specif())) == NULL)
		return (-1);
	s = has_prec_s(elem, s);
	if ((elem->todo_gab = elem->gab - (int)ft_strlen(s)) <= 0)
		elem->todo_gab = 0;
	make_s(elem, s);
	nb = elem->todo_gab + (int)ft_strlen(s);
	ft_free_struct(elem);
	return (nb);
}
