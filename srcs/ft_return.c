/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:32:02 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/27 11:32:14 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_return(t_struct *elem, char *s)
{
	int len;

	len = (int)ft_strlen(s);
	if (ft_atoi(s) == 0 && elem->prec_null == 1)
		len = 0;
	if (elem->prec > len)
	{
		if (elem->gab > elem->prec + elem->ret)
			return (elem->gab);
		else
			return (elem->prec + elem->ret + elem->neg);
	}
	else
	{
		if (elem->gab > len + elem->ret)
			return (elem->gab);
		else
			return (len + elem->ret);
	}
}
