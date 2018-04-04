/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 11:00:31 by vbaudron          #+#    #+#             */
/*   Updated: 2016/11/23 15:30:12 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(int n)
{
	int				i;
	unsigned int	nb;

	nb = n;
	i = 0;
	if (n < 0)
	{
		i++;
		nb = n * -1;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	if (nb < 10)
		i++;
	return (i);
}

static char		*ft_fulfill(int n, char *s, int k)
{
	unsigned int nb;

	nb = n;
	if (n < 0)
	{
		s[0] = '-';
		nb = n * -1;
	}
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

char			*ft_itoa(int n)
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
