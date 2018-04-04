/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imax_toa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:31:03 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/27 12:57:55 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_count(intmax_t n)
{
	int			i;
	intmax_t	nb;

	nb = n;
	i = 0;
	while (nb <= -10)
	{
		nb = nb / 10;
		i++;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	if (nb < 10 && nb > -10)
		i++;
	if (nb < 0)
		i++;
	return (i);
}

static char		*ft_fulfill(intmax_t n, char *s, int k)
{
	intmax_t nb;

	nb = n;
	s[k] = '\0';
	k--;
	if (n < 0)
		s[0] = '-';
	while (nb <= -10)
	{
		s[k] = (nb % -10) * -1 + '0';
		nb = nb / 10;
		k--;
	}
	while (nb >= 10)
	{
		s[k] = nb % 10 + '0';
		nb = nb / 10;
		k--;
	}
	if (nb < 0)
		s[k] = (nb * -1) + '0';
	else
		s[k] = nb + '0';
	return (s);
}

char			*ft_imax_toa(intmax_t n)
{
	int		k;
	char	*str;

	k = ft_count(n);
	str = (char*)malloc(sizeof(char) * (k + 1));
	if (str == 0)
		return (NULL);
	str = ft_fulfill(n, str, k);
	return (str);
}
