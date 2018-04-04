/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:50:05 by vbaudron          #+#    #+#             */
/*   Updated: 2016/12/07 12:50:13 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int i;
	int j;
	int result;

	i = 0;
	j = 0;
	result = 0;
	while ((str[i] >= 0 && str[i] <= 32) || str[i] == 127)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		j = i;
		if (str[i + 1] > '9' || str[i + 1] < '0')
			return (0);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i++] - '0';
		if ((str[i] == '\0' || str[i] < '0' || str[i] > '9') && str[j] == '-')
			return (result * -1);
		if ((str[i] == '\0' || str[i] < '0' || str[i] > '9') && str[j] != '-')
			return (result);
	}
	return (0);
}
