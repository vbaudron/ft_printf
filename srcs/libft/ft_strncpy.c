/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:45:09 by vbaudron          #+#    #+#             */
/*   Updated: 2016/11/23 13:35:43 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned int i;
	unsigned int dlen;

	i = 0;
	dlen = ft_strlen(dst);
	while (i < len && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (src[i] == '\0')
	{
		while (i < dlen && i < len)
		{
			dst[i] = '\0';
			i++;
		}
	}
	return (dst);
}
