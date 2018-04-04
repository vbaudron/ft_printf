/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 10:59:33 by vbaudron          #+#    #+#             */
/*   Updated: 2016/11/23 15:41:58 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		k;
	char	*p;

	k = 0;
	p = 0;
	i = ft_strlen(s) - 1;
	if ((unsigned char)c == '\0')
		return ((char *)&s[i + 1]);
	if (s[k] == '\0')
		return (p);
	while (s[i] != (unsigned char)c && i > 0)
		i--;
	if (s[i] != (unsigned char)c && i == 0)
		return (NULL);
	return ((char *)&s[i]);
}
