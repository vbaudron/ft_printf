/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:30:51 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/27 11:30:54 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_free_struct(t_struct *elem)
{
	if (elem->has_flag == 1)
	{
		free(elem->flags);
		elem->flags = NULL;
	}
	if (elem->modif)
	{
		free(elem->modif);
		elem->modif = NULL;
	}
	free(elem);
	elem = NULL;
}
