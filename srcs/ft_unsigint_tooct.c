/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigint_tooct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:33:17 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/27 13:43:46 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_count_oct(uintmax_t nb)
{
	int i;
	int n;
	int count;

	i = 1;
	n = 0;
	count = 0;
	while (nb > 8)
	{
		n = n + (nb % 8) * i;
		nb = nb / 8;
		i = i * 10;
		count++;
	}
	if (nb > 0)
		count++;
	return (count);
}

void	fullfill_oct_str(char **s, int count, uintmax_t nb)
{
	uintmax_t	n;
	uintmax_t	oct;
	int			i;

	n = 0;
	oct = 0;
	i = 1;
	while (nb > 8)
	{
		oct = nb % 8;
		(*s)[count] = oct + '0';
		n = n + oct * i;
		nb = nb / 8;
		i = i * 10;
		count--;
	}
	(*s)[count] = nb + '0';
	n = n + nb * i;
}

int		ft_uintmax_oct_toa(uintmax_t nb, char **s)
{
	int count;

	count = ft_count_oct(nb);
	if (nb == 0)
		count = 1;
	*s = ft_strnew(count + 1);
	if (s == NULL)
		return (-1);
	if (nb == 0)
	{
		(*s)[0] = '0';
		return (1);
	}
	fullfill_oct_str(s, count - 1, nb);
	return (1);
}
