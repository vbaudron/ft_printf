/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:40:41 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/27 14:12:27 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	initialized_flags(t_flag *my_flags)
{
	my_flags->moins = 0;
	my_flags->zero = 0;
	my_flags->diese = 0;
	my_flags->plus = 0;
	my_flags->space = 0;
}

void	set_values(t_flag *my_flags, const char **format, int i, int *k)
{
	if ((*format)[i] == '-')
		my_flags->moins = 1;
	if ((*format)[i] == ' ')
		my_flags->space = 1;
	if ((*format)[i] == '#')
		my_flags->diese = 1;
	if ((*format)[i] == '+')
		my_flags->plus = 1;
	if ((*format)[i] == '0')
	{
		while ((*format)[i - *k] == '0')
			(*k)++;
		if (ft_isdigit((*format)[i - *k]) == 0)
			my_flags->zero = 1;
	}
}

t_flag	*what_flags(const char **format, int i, int j, char **t_specif)
{
	int		is_prec;
	t_flag	*my_flags;
	int		k;

	is_prec = 0;
	k = 0;
	if ((my_flags = malloc(sizeof(t_flag))) == NULL)
		return (NULL);
	initialized_flags(my_flags);
	while ((*format)[i] != (*t_specif)[j])
	{
		if ((*format)[i] == '.')
			is_prec = 1;
		if ((*format)[i] == '-' || (*format)[i] == '+' || (*format)[i] == ' '
		|| (*format)[i] == '#' || ((*format)[i] == '0' && is_prec == 0))
			set_values(my_flags, format, i, &k);
		i++;
	}
	return (my_flags);
}
