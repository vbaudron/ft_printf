/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_specif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:33:45 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/27 13:45:48 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	has_specif(const char **format, int i, char **t_specif)
{
	int save_i;
	int j;

	save_i = i;
	j = 0;
	while (((*format)[i] >= '0' && (*format)[i] <= '9') || (*format)[i] == '#'
	|| (*format)[i] == '-' || (*format)[i] == '.' || (*format)[i] == '*' ||
	(*format)[i] == '+' || (*format)[i] == ' ' || (*format)[i] == 'h' ||
	(*format)[i] == 'l' || (*format)[i] == 'z' || (*format)[i] == 'j' ||
	(*format)[i] == 'z')
		i++;
	if ((*format)[i] == '\0')
		return (-1);
	while ((*format)[i] != (*t_specif)[j] && (*t_specif)[j] != '\0')
		j++;
	if ((*t_specif)[j] == '\0')
		return (-1);
	return (j);
}
