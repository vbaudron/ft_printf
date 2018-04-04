/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:32:50 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/27 13:42:39 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_modif_long_u(t_struct *elem, uintmax_t u, uintmax_t *nbr)
{
	if (elem->modif[1] == 'h')
		*nbr = (unsigned char)u;
	else
		*nbr = (unsigned short int)(u);
}

char	*ft_modif_u(t_struct *elem, uintmax_t u)
{
	uintmax_t nbr;

	nbr = u;
	if (elem->specif == 'U')
		elem->modif[0] = 'l';
	if (elem->modif[0] == 'h')
		ft_modif_long_u(elem, u, &nbr);
	else if (elem->modif[0] == 'l')
	{
		if (elem->modif[1] == 'l')
			nbr = (unsigned long long int)(u);
		else
			nbr = (unsigned long int)(u);
	}
	else if (elem->modif[0] == 'z')
		nbr = (size_t)u;
	else if (elem->modif[0] == 'j')
		nbr = (uintmax_t)nbr;
	else
		nbr = (unsigned int)nbr;
	return (ft_uimax_toa(nbr));
}

void	gab_todo_u(t_struct *elem, char *s)
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

int		ft_u(va_list args, const char **format, int i)
{
	uintmax_t	u;
	int			nb;
	t_struct	*elem;
	char		*s;

	u = va_arg(args, uintmax_t);
	nb = 0;
	elem = NULL;
	s = NULL;
	if ((elem = crea_struct(elem, format, i, crea_t_specif())) == NULL)
		return (-1);
	s = ft_modif_u(elem, u);
	gab_todo_u(elem, s);
	make_u(elem, s);
	nb = ft_return(elem, s);
	free(s);
	s = NULL;
	ft_free_struct(elem);
	return (nb);
}
