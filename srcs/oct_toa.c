/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oct_toa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:35:07 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/27 13:55:19 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_count_oct(uintmax_t n)
{
	int			i;
	uintmax_t	nb;

	nb = n;
	i = 0;
	while (nb >= 8)
	{
		nb = nb / 8;
		i++;
	}
	if (nb < 8)
		i++;
	return (i);
}

static char		*ft_fulfill_oct(uintmax_t n, char *s, int k)
{
	uintmax_t nb;

	nb = n;
	s[k] = '\0';
	k--;
	while (nb >= 8)
	{
		s[k] = nb % 8 + '0';
		nb = nb / 8;
		k--;
	}
	if (nb < 8)
		s[k] = nb + '0';
	return (s);
}

char			*ft_oct_toa(uintmax_t n)
{
	int		k;
	char	*str;

	k = ft_count_oct(n);
	str = (char*)malloc(sizeof(char) * (k + 1));
	if (str == 0)
		return (NULL);
	str = ft_fulfill_oct(n, str, k);
	return (str);
}
