/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimax_toa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:33:00 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/27 11:33:01 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_count(uintmax_t n)
{
	int			i;
	uintmax_t	nb;

	nb = n;
	i = 0;
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	if (nb < 10)
		i++;
	return (i);
}

static char		*ft_fulfill(uintmax_t n, char *s, int k)
{
	uintmax_t nb;

	nb = n;
	s[k] = '\0';
	k--;
	while (nb >= 10)
	{
		s[k] = nb % 10 + '0';
		nb = nb / 10;
		k--;
	}
	if (nb < 10)
		s[k] = nb + '0';
	return (s);
}

char			*ft_uimax_toa(uintmax_t n)
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
