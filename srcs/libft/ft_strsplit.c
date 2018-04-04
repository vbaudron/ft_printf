/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:32:17 by vbaudron          #+#    #+#             */
/*   Updated: 2016/12/02 16:00:32 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words(char const *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			j++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (j);
}

static int		ft_len_word(char const *s, int i, char c)
{
	int j;

	j = 0;
	while (s[i + j] != c && s[i + j])
		j++;
	return (j);
}

static char		*ft_stricpy(char const *s, char *dst, int i, char c)
{
	int j;

	j = 0;
	while (s[i] != c && s[i])
	{
		dst[j] = s[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dst);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	j = 0;
	if (s)
	{
		str = (char**)malloc(sizeof(char*) * (ft_count_words(s, c) + 1));
		if (str == 0)
			return (NULL);
		while (i < (ft_count_words(s, c)))
		{
			while (s[j] == c)
				j++;
			if (!(str[i] = malloc(sizeof(char) * (ft_len_word(s, j, c) + 1))))
				return (0);
			str[i] = ft_stricpy(s, str[i], j, c);
			j = j + ft_len_word(s, j, c);
			i++;
		}
		str[i] = 0;
		return (str);
	}
	return (NULL);
}
