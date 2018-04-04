/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:55:03 by vbaudron          #+#    #+#             */
/*   Updated: 2016/11/30 17:15:44 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned int i;

	i = 0;
	if (s1 && s2)
	{
		if (n == 0)
			return (1);
		while (s1[i] == s2[i])
		{
			if (i == (n - 1))
				return (1);
			i++;
		}
		return (0);
	}
	return (0);
}
