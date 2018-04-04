/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:30:36 by vbaudron          #+#    #+#             */
/*   Updated: 2016/11/30 15:35:01 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	unsigned int	i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ss1 = (unsigned char*)s1;
	ss2 = (unsigned char*)s2;
	if (len == 0)
		return (0);
	while (ss1[i] == ss2[i] && i < len - 1)
	{
		i++;
		if (ss1[i] == ss2[i] && i == len - 1)
			return (0);
	}
	return (ss1[i] - ss2[i]);
}
