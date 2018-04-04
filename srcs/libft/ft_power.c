/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:35:55 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/27 11:35:59 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_power(int nb, int pow)
{
	int result;
	int i;

	i = 1;
	result = nb;
	while (i < pow)
	{
		result = result * nb;
		i++;
	}
	return (result);
}
