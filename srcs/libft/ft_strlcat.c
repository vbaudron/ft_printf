/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:50:34 by vbaudron          #+#    #+#             */
/*   Updated: 2016/11/23 15:30:52 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	unsigned int	i;
	unsigned int	slen;
	unsigned int	dlen;
	unsigned int	k;

	i = 0;
	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	k = 0;
	while (dst[i])
		i++;
	if (i >= n)
		return (slen + n);
	while (i < (n - 1) && src[k])
	{
		dst[i] = src[k];
		i++;
		k++;
	}
	dst[i] = '\0';
	return (dlen + slen);
}
