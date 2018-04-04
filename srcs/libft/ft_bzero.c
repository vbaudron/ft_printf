/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 14:54:05 by vbaudron          #+#    #+#             */
/*   Updated: 2016/11/23 16:37:19 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *b, size_t len)
{
	size_t					i;
	unsigned char			*str;

	i = 0;
	str = (unsigned char *)b;
	while (i < len)
	{
		str[i] = '\0';
		i++;
	}
	b = str;
}
