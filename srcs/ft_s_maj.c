/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_S_maj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:32:19 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/27 13:36:04 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			has_gab_s_maj(t_struct *elem)
{
	int j;

	j = 0;
	while (j++ < elem->todo_gab)
		ft_putchar(' ');
	return (j);
}

wchar_t		*has_prec_s_maj(t_struct *elem, wchar_t *s)
{
	int		i;
	wchar_t	*save;

	i = 0;
	save = NULL;
	if (elem->prec > 0 || elem->prec_null == 1)
	{
		save = malloc(sizeof(wchar_t) * (elem->prec + 1));
		while (i < elem->prec)
		{
			save[i] = s[i];
			i++;
		}
		return (save);
	}
	return (s);
}

size_t		wstr_len(wchar_t *s)
{
	size_t	nb;

	nb = 0;
	while (*s)
	{
		if (*s <= 0x7F)
			nb++;
		else if (*s <= 0x7FF)
			nb += 2;
		else if (*s <= 0xFFF)
			nb += 3;
		else if (*s <= 0x10FFFF)
			nb += 4;
		s++;
	}
	return (nb);
}

void		deal_with_s_maj(t_struct *elem, wchar_t *s)
{
	if (elem->has_flag && elem->flags->moins == 1)
	{
		ft_putnwstr(s, wstr_len(s));
		has_gab_s_maj(elem);
	}
	else
	{
		has_gab_s_maj(elem);
		ft_putnwstr(s, wstr_len(s));
	}
}

int			ft_s_maj(va_list args, const char **format, int i)
{
	wchar_t		*s;
	int			nb;
	t_struct	*elem;

	nb = 0;
	elem = NULL;
	s = va_arg(args, wchar_t*);
	if (!s)
	{
		ft_putstr("L(null)");
		return (6);
	}
	if ((elem = crea_struct(elem, format, i, crea_t_specif())) == NULL)
		return (-1);
	s = has_prec_s_maj(elem, s);
	if ((elem->todo_gab = elem->gab - (int)wstr_len(s)) <= 0)
		elem->todo_gab = 0;
	deal_with_s_maj(elem, s);
	nb = elem->todo_gab + (int)wstr_len(s);
	ft_free_struct(elem);
	return (nb);
}
