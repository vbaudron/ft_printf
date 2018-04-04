/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:11:33 by vbaudron          #+#    #+#             */
/*   Updated: 2016/11/23 15:31:37 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!little[i])
		return ((char*)big);
	while (big[i] && i < len)
	{
		if (big[i] == little[j])
		{
			j++;
			if (little[j] == '\0')
				return ((char*)&big[i]);
			while (big[i + j] == little[j] && (i + j) < len)
			{
				j++;
				if (little[j] == '\0')
					return ((char*)&big[i]);
			}
		}
		j = 0;
		i++;
	}
	return (0);
}
