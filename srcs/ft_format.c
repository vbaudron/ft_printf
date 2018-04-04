/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:28:44 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/27 12:56:49 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		no_args_need(const char **format, int i, int j)
{
	if (j == 14)
		return (ft_pourcent(format, i));
	return (empty_specif(format, i, 0, 0));
}

int		normal_format(const char **format, int i, int *nb)
{
	while ((*format)[i] != '\0' && (*format)[i] != '%')
	{
		ft_putchar((*format)[i++]);
		(*nb)++;
	}
	return (i);
}

int		ft_format(const char **format, va_list args, char **t_spe, f_args **t)
{
	int i;
	int j;
	int k;
	int nb;

	i = 0;
	j = 0;
	k = 0;
	nb = 0;
	while ((*format)[i] != '\0')
	{
		i = normal_format(format, i, &nb);
		if ((*format)[i] == '%' && (*format)[++i] != '\0')
		{
			if ((j = has_specif(format, i, t_spe)) != 14 && j != -1)
				if ((*t == NULL && crea_targ(t) == -1) ||
					(k = (*t)[j](args, format, i)) == -1)
					return (-1);
			if ((j == 14 || j == -1) && (k = no_args_need(format, i, j)) == -1)
				return (nb);
			i = i + ft_spec_len(j, format, i, t_spe);
			nb = nb + k;
		}
	}
	return (nb);
}
