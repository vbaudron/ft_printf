/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:31:29 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/27 13:24:52 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	gab_todo_p(t_struct *elem, char *s)
{
	int	len;

	len = (int)ft_strlen(s);
	if (elem->gab > elem->prec)
	{
		if (elem->prec >= len)
			elem->todo_gab = elem->gab - elem->prec;
		else
			elem->todo_gab = elem->gab - len;
	}
	else
		elem->todo_gab = 0;
}

int		ft_p(va_list args, const char **format, int i)
{
	uintmax_t	p;
	int			nb;
	t_struct	*elem;
	char		*s;

	p = va_arg(args, uintmax_t);
	nb = 0;
	elem = NULL;
	s = NULL;
	if ((elem = crea_struct(elem, format, i, crea_t_specif())) == NULL)
		return (-1);
	p = (size_t)p;
	s = ito_adress(p);
	gab_todo_p(elem, s);
	make_p(elem, s);
	nb = ft_return(elem, s);
	free(s);
	s = NULL;
	ft_free_struct(elem);
	return (nb);
}
