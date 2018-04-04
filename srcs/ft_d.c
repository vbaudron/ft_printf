/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:30:36 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/27 12:13:24 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_modif_d(t_struct *elem, intmax_t d)
{
	intmax_t	nbr;

	nbr = d;
	if (elem->specif == 'D')
		elem->modif[0] = 'l';
	if (elem->modif[0] == 'h')
		if (elem->modif[1] == 'h')
			nbr = (char)d;
		else
			nbr = (short int)(d);
	else if (elem->modif[0] == 'l')
	{
		if (elem->modif[1] == 'l')
			nbr = (long long int)(d);
		else
			nbr = (long int)(d);
	}
	else if (elem->modif[0] == 'z')
		nbr = (size_t)d;
	else if (elem->modif[0] == 'j')
		nbr = (intmax_t)nbr;
	else
		nbr = (int)nbr;
	return (ft_imax_toa(nbr));
}

void	count_todo_gab_d(t_struct *elem, char *s)
{
	int			len;

	len = (int)ft_strlen(s);
	if (elem->gab > 0 && elem->prec > len - elem->neg)
		elem->todo_gab = elem->gab - elem->prec - elem->neg;
	if (elem->gab > 0 && elem->prec <= len - elem->neg)
	{
		if (ft_atoi(s) == 0 && elem->prec_null == 1)
			elem->todo_gab = elem->gab;
		else
			elem->todo_gab = elem->gab - len;
	}
}

int		ft_d(va_list args, const char **format, int i)
{
	intmax_t	d;
	int			nb;
	t_struct	*elem;
	char		*s;

	d = va_arg(args, intmax_t);
	nb = 0;
	elem = NULL;
	s = NULL;
	if ((elem = crea_struct(elem, format, i, crea_t_specif())) == NULL)
		return (-1);
	s = ft_modif_d(elem, d);
	elem->neg = ft_search_str(s, '-');
	count_todo_gab_d(elem, s);
	make_d(elem, s, 0);
	nb = ft_return(elem, s);
	free(s);
	s = NULL;
	ft_free_struct(elem);
	return (nb);
}
