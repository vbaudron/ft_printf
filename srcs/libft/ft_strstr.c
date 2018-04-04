/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:46:54 by vbaudron          #+#    #+#             */
/*   Updated: 2016/11/23 15:32:05 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!little[i])
		return ((char*)big);
	while (big[i])
	{
		if (big[i] == little[j])
		{
			j++;
			if (little[j] == '\0')
				return ((char*)&big[i]);
			while (big[i + j] == little[j])
			{
				j++;
				if (little[j] == '\0')
					return ((char*)&big[i]);
			}
		}
		j = 0;
		i++;
	}
	return (NULL);
}
