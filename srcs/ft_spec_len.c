/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:32:33 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/27 13:38:43 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	count_no_spec(const char **format, int i)
{
	int k;

	k = 0;
	while ((*format)[i + k] && ((*format)[i + k] == ' ' ||
		(*format)[i + k] == '#' || ft_isdigit((*format)[i + k]) == 1 ||
		(*format)[i + k] == '+' || (*format)[i + k] == '-' ||
		(*format)[i + k] == 'h' || (*format)[i + k] == 'l' ||
		(*format)[i + k] == '.'))
		k++;
	return (k);
}

int	has_moins(const char **format, int i)
{
	int moins;
	int point;
	int k;

	moins = 0;
	point = 0;
	k = 0;
	while ((*format[i + k]) && ((*format)[i + k] == ' ' ||
	(*format)[i + k] == '#' || ft_isdigit((*format)[i + k]) == 1 ||
	(*format)[i + k] == '+' || (*format)[i + k] == '-' ||
	(*format)[i + k] == 'h' || (*format)[i + k] == 'l' ||
	(*format)[i + k] == '.'))
	{
		if ((*format)[i + k] == '.')
			point++;
		if (point == 0 && (*format)[i + k] == '-')
		{
			moins++;
			return (1);
		}
		k++;
	}
	return (-1);
}

int	ft_spec_len(int j, const char **format, int i, char **t_specif)
{
	int nb;
	int k;

	nb = 0;
	k = 0;
	if (j == -1)
	{
		nb = count_no_spec(format, i);
		if ((*format)[i + nb])
		{
			if (no_specif_gab(format, i + nb) > 1 && has_moins(format, i) == 1)
				return (nb + 1);
			return (nb);
		}
		else
			return (-1);
	}
	else
	{
		while ((*format)[i + nb] != (*t_specif)[j])
			nb++;
		return (nb + 1);
	}
}
