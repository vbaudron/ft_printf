/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:33:31 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/27 13:45:07 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	has_flags(const char **format, int i, int j, char **t_specif)
{
	while ((*format)[i] != (*t_specif)[j])
	{
		if ((*format)[i] == '.')
			return (0);
		if ((*format)[i] == '-' || (*format)[i] == '+' || (*format)[i] == ' '
		|| (*format)[i] == '#' || (*format)[i] == '0')
			return (1);
		i++;
	}
	return (0);
}
