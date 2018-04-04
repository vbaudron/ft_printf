/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_specif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:29:56 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/27 12:49:59 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		find_gab_empty(const char **format, int i, int *point, int *moins)
{
	int k;
	int zero;

	k = 0;
	zero = 0;
	while ((*format)[i + k] && ((*format)[i + k] == ' ' ||
		(*format)[i + k] == '#' || ft_isdigit((*format)[i + k]) == 1 ||
		(*format)[i + k] == '+' || (*format)[i + k] == '-' ||
		(*format)[i + k] == 'h' || (*format)[i + k] == 'l' ||
		(*format)[i + k] == '.'))
	{
		if ((*format)[i + k] == '.')
			(*point)++;
		if ((*format)[i + k] == '-' && point == 0)
			(*moins)++;
		if ((*format)[i + k] == '0' && ft_isdigit((*format)[i + k - 1]) == 0)
			zero++;
		k++;
	}
	return (zero);
}

int		put_gab(const char **format, int i, int current_gab, int j)
{
	int k;
	int zero;
	int point;
	int moins;

	k = 0;
	moins = 0;
	zero = 0;
	point = 0;
	zero = find_gab_empty(format, i, &point, &moins);
	if (moins > 0)
	{
		ft_putchar((*format)[i + j]);
		while (k++ < current_gab)
			ft_putchar(' ');
		return (current_gab + 1);
	}
	while (k++ < current_gab)
	{
		if (zero > 0)
			ft_putchar('0');
		else
			ft_putchar(' ');
	}
	return (current_gab);
}

int		empty_specif(const char **format, int i, int point, int moins)
{
	int j;
	int current_gab;

	j = 0;
	current_gab = 0;
	while ((*format)[i + j] && ((*format)[i + j] == ' ' ||
			(*format)[i + j] == '#' || ft_isdigit((*format)[i + j]) == 1 ||
			(*format)[i + j] == '+' || (*format)[i + j] == '-' ||
			(*format)[i + j] == 'h' || (*format)[i + j] == 'l' ||
			(*format)[i + j] == '.'))
	{
		if ((*format)[i + j] == '.')
			point++;
		if (point == 0 && (*format)[i + j] == '-')
			moins++;
		if (point == 0 && ft_isdigit((*format)[i + j]) == 1)
		{
			if ((current_gab = no_specif_gab(format, i + j)) > 1)
				return (put_gab(format, i, current_gab, j));
		}
		j++;
	}
	if ((*format)[i + j] && (*format)[i + j] == 'Z')
		return (0);
	return (-1);
}
