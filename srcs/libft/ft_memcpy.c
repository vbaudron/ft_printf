/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:20:52 by vbaudron          #+#    #+#             */
/*   Updated: 2016/11/30 17:15:15 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*dst1;
	unsigned char	*src1;

	i = 0;
	src1 = (unsigned char*)src;
	dst1 = (unsigned char*)dst;
	while (i < n)
	{
		dst1[i] = src1[i];
		i++;
	}
	dst = dst1;
	return (dst);
}
