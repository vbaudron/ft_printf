/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:33:05 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/27 13:25:57 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*t_specif;
	f_args	*tab;
	int		nb;

	nb = 0;
	tab = NULL;
	t_specif = NULL;
	va_start(args, format);
	if ((t_specif = crea_t_specif()) == NULL)
		return (-1);
	nb = ft_format(&format, args, &t_specif, &tab);
	if (nb == -1)
		return (-1);
	va_end(args);
	if (t_specif)
	{
		free(t_specif);
		t_specif = NULL;
	}
	if (tab)
		free_targs(&tab);
	return (nb);
}
