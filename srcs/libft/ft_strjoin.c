/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 15:35:25 by vbaudron          #+#    #+#             */
/*   Updated: 2016/11/30 17:18:19 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_add_begin(char *str, const char *s1, int j)
{
	int i;

	i = 0;
	if (str && s1)
	{
		while (i < j)
		{
			str[i] = s1[i];
			i++;
		}
		return (str);
	}
	return (NULL);
}

static char		*ft_add_end(char *str, const char *s2, int j, int k)
{
	int i;

	i = 0;
	if (str && s2)
	{
		while (j < k)
		{
			str[j] = s2[i];
			j++;
			i++;
		}
		str[j] = '\0';
		return (str);
	}
	return (NULL);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	int		j;
	int		k;
	char	*str;

	k = 0;
	j = 0;
	if (s1 && s2)
	{
		j = ft_strlen(s1);
		k = ft_strlen(s2) + j;
		str = (char*)malloc(sizeof(char) * k + 1);
		if (str == 0)
			return (NULL);
		str = ft_add_begin(str, s1, j);
		str = ft_add_end(str, s2, j, k);
		return (str);
	}
	if (s1 && !s2)
	{
		str = (char*)malloc(sizeof(char) * k + 1);
		str = ft_strcpy(str, s1);
		return (str);
	}
	return (NULL);
}
