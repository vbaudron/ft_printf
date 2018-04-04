/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 15:47:44 by vbaudron          #+#    #+#             */
/*   Updated: 2016/12/02 16:21:23 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(char const *s)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = ft_strlen(s);
	k = j - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (i == j)
		return (0);
	while (s[k] == ' ' || s[k] == '\n' || s[k] == '\t')
	{
		k--;
		i++;
	}
	return (j - i);
}

static char		*ft_strnospace(char const *src, char *dst, size_t len)
{
	int				i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (src[i] == ' ' || src[i] == '\n' || src[i] == '\t')
		i++;
	while (j < len)
	{
		dst[j] = src[i + j];
		j++;
	}
	return (dst);
}

char			*ft_strtrim(char const *s)
{
	unsigned int	len;
	char			*str;

	if (s)
	{
		len = ft_count(s);
		if (len == 0)
		{
			str = (char*)malloc(sizeof(char) * 1);
			if (str == NULL)
				return (0);
			*str = '\0';
			return (str);
		}
		str = (char*)malloc(sizeof(char) * len + 1);
		if (str == 0)
			return (NULL);
		str = ft_strnospace(s, str, len);
		str[len] = '\0';
		return (str);
	}
	return (NULL);
}
