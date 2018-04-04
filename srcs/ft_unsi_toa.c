/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsi_toa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:33:10 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/27 11:33:13 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static unsigned int		ft_count(unsigned int n)
{
	unsigned int				i;

	i = 0;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	if (n < 10)
		i++;
	return (i);
}

static char				*ft_fulfill(unsigned int n, char *s, unsigned int k)
{
	s[k] = '\0';
	k--;
	while (n >= 10)
	{
		s[k] = n % 10 + '0';
		n = n / 10;
		k--;
	}
	if (n < 10)
		s[k] = n + '0';
	return (s);
}

char					*ft_unsi_toa(unsigned int n)
{
	unsigned int	k;
	char			*str;

	k = ft_count(n);
	str = (char*)malloc(sizeof(char) * (k + 1));
	if (str == 0)
		return (NULL);
	str = ft_fulfill(n, str, k);
	return (str);
}
