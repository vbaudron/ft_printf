/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crea_targ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 12:18:15 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/27 14:16:42 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	crea_targ(f_args **tab)
{
	if ((*tab = malloc(sizeof(f_args) * 14)) == NULL)
		return (-1);
	(*tab)[0] = &ft_s;
	(*tab)[1] = &ft_s_maj;
	(*tab)[2] = &ft_p;
	(*tab)[3] = &ft_d;
	(*tab)[4] = &ft_d;
	(*tab)[5] = &ft_d;
	(*tab)[6] = &ft_o;
	(*tab)[7] = &ft_o;
	(*tab)[8] = &ft_u;
	(*tab)[9] = &ft_u;
	(*tab)[10] = &ft_x;
	(*tab)[11] = &ft_x;
	(*tab)[12] = &ft_c;
	(*tab)[13] = &ft_c;
	return (1);
}
