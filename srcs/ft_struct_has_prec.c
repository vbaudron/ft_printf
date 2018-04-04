/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_has_prec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:32:39 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/27 13:40:29 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	cpy_prec(const char **format, char **s, int i)
{
	int k;

	k = 0;
	while ((*format)[i + k] >= '0' && (*format)[i + k] <= '9')
	{
		(*s)[k] = (*format)[i + k];
		k++;
	}
}

int		has_precision(const char **format, int i, int j, char **t_specif)
{
	int		k;
	int		prec;
	char	*s;

	k = 0;
	while ((*format)[i] != (*t_specif)[j])
	{
		if ((*format)[i++] == '.')
		{
			if ((*format)[i] < '0' && (*format)[i] > '9')
				return (0);
			while ((*format)[i + k] >= '0' && (*format)[i + k] <= '9')
				k++;
			if ((s = ft_strnew(k + 1)) == NULL)
				return (0);
			cpy_prec(format, &s, i);
			prec = ft_atoi(s);
			free(s);
			s = NULL;
			return (prec);
		}
	}
	return (0);
}

int		ft_struct_has_prec(const char **format, int i, int j, char **t_specif)
{
	int k;
	int l;

	k = 0;
	l = i;
	while ((*format)[i] != (*t_specif)[j])
	{
		if ((*format)[i] == '.')
		{
			i++;
			while ((*format)[i + k] == '0'
			|| (*format)[i + k] == (*t_specif)[j])
			{
				if ((*format)[i + k] == (*t_specif)[j])
					return (-1);
				k++;
			}
			if ((*format)[i + k] > '0' && (*format)[i + k] <= '9')
				return (has_precision(format, l, j, t_specif));
		}
		i++;
	}
	return (has_precision(format, i, j, t_specif));
}
