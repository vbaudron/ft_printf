/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:33:26 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/27 13:44:39 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

uintmax_t	ft_modif_x(t_struct *elem, uintmax_t x)
{
	uintmax_t nbr;

	nbr = x;
	if (elem->modif[0] == 'h')
	{
		if (elem->modif[1] == 'h')
			nbr = (unsigned char)x;
		else
			nbr = (unsigned short int)(x);
	}
	else if (elem->modif[0] == 'l')
	{
		if (elem->modif[1] == 'l')
			nbr = (unsigned long long int)(x);
		else
			nbr = (unsigned long int)(x);
	}
	else if (elem->modif[0] == 'z')
		nbr = (size_t)x;
	else if (elem->modif[0] == 'j')
		nbr = (uintmax_t)x;
	else
		nbr = (unsigned int)x;
	return (nbr);
}

int			ft_x(va_list args, const char **format, int i)
{
	uintmax_t	x;
	int			nb;
	t_struct	*elem;
	char		*s;

	x = va_arg(args, uintmax_t);
	nb = 0;
	elem = NULL;
	s = NULL;
	if ((elem = crea_struct(elem, format, i, crea_t_specif())) == NULL)
		return (-1);
	x = ft_modif_x(elem, x);
	s = ft_ito_hexa(x, elem);
	if (elem->gab > 0 && elem->prec < (int)ft_strlen(s))
		if ((elem->todo_gab = elem->gab - (int)ft_strlen(s)) < 0)
			elem->todo_gab = 0;
	if (elem->gab > 0 && elem->prec > (int)ft_strlen(s))
		if ((elem->todo_gab = elem->gab - elem->prec) < 0)
			elem->todo_gab = 0;
	make_x(elem, s, 0);
	nb = ft_return(elem, s);
	free(s);
	s = NULL;
	ft_free_struct(elem);
	return (nb);
}
