/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_specif_gab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:34:58 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/27 13:54:55 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		no_specif_gab(const char **format, int start)
{
	int		k;
	char	*s;
	int		current_gab;

	k = 0;
	s = NULL;
	current_gab = 0;
	while (ft_isdigit((*format)[start + k]) == 1)
		k++;
	s = ft_strnew(k + 1);
	while (k > 0)
	{
		s[k - 1] = (*format)[start + k];
		k--;
	}
	current_gab = ft_atoi(s);
	free(s);
	s = NULL;
	return (current_gab);
}
