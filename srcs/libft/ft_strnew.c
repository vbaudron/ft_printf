/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:56:01 by vbaudron          #+#    #+#             */
/*   Updated: 2016/11/23 15:52:41 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = (char*)ft_memalloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	while (i <= size)
		str[i++] = '\0';
	return (str);
}
