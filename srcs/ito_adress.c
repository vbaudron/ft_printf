/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ito_adress.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:33:53 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/27 13:46:38 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_hexa_adress(uintmax_t rest, char c)
{
	if (rest < 10)
		return (c);
	else if (rest == 10)
		c = 'a';
	else if (rest == 11)
		c = 'b';
	else if (rest == 12)
		c = 'c';
	else if (rest == 13)
		c = 'd';
	else if (rest == 14)
		c = 'e';
	else if (rest == 15)
		c = 'f';
	else
		c = 'z';
	return (c);
}

int		fullfill_adress(char **s, uintmax_t result, int i)
{
	uintmax_t rest;

	rest = 0;
	while (result >= 16)
	{
		rest = result % 16;
		result = result / 16;
		(*s)[i] = ft_hexa_adress(rest, rest + '0');
		if ((*s)[i] == 'z')
			return (-1);
		i--;
	}
	rest = result % 16;
	(*s)[0] = ft_hexa_adress(rest, rest + '0');
	return (1);
}

char	*ito_adress(uintmax_t nb)
{
	char		*s;
	uintmax_t	result;
	int			i;

	i = 0;
	result = nb;
	while (nb > 16)
	{
		nb = nb / 16;
		i++;
	}
	i++;
	s = ft_strnew(i + 1);
	if (s == NULL)
		return (NULL);
	if (fullfill_adress(&s, result, i - 1) == -1)
		return (NULL);
	return (s);
}
