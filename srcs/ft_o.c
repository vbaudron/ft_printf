/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:31:19 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/27 13:24:21 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_modif_long_o(t_struct *elem, uintmax_t o, uintmax_t *nbr)
{
	if (elem->modif[1] == 'h')
		*nbr = (unsigned char)o;
	else
		*nbr = (unsigned short int)(o);
}

uintmax_t	ft_modif_o(t_struct *elem, uintmax_t o)
{
	uintmax_t nbr;

	nbr = o;
	if (elem->specif == 'O')
		elem->modif[0] = 'l';
	if (elem->modif[0] == 'h')
		ft_modif_long_o(elem, o, &nbr);
	else if (elem->modif[0] == 'l')
	{
		if (elem->modif[1] == 'l')
			nbr = (unsigned long long int)(o);
		else
			nbr = (unsigned long int)(o);
	}
	else if (elem->modif[0] == 'z')
		nbr = (size_t)o;
	else if (elem->modif[0] == 'j')
		nbr = (uintmax_t)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}

void		gab_todo_o(t_struct *elem, char *s)
{
	int	len;

	len = (int)ft_strlen(s);
	if (elem->gab > 0 && elem->prec > len)
		elem->todo_gab = elem->gab - elem->prec;
	if (elem->gab > 0 && elem->prec <= len)
	{
		if (ft_atoi(s) == 0 && elem->prec_null == 1)
			elem->todo_gab = elem->gab;
		else
			elem->todo_gab = elem->gab - len;
	}
}

int			ft_o(va_list args, const char **format, int i)
{
	uintmax_t	o;
	int			nb;
	t_struct	*elem;
	char		*s;

	o = va_arg(args, uintmax_t);
	nb = 0;
	elem = NULL;
	s = NULL;
	if ((elem = crea_struct(elem, format, i, crea_t_specif())) == NULL)
		return (-1);
	o = ft_modif_o(elem, o);
	ft_uintmax_oct_toa(o, &s);
	gab_todo_o(elem, s);
	make_o(elem, s, 0);
	nb = ft_return(elem, s);
	free(s);
	s = NULL;
	ft_free_struct(elem);
	return (nb);
}
