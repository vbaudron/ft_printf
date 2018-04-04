/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crea_t_specif.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:29:27 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/27 11:29:36 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*crea_t_specif(void)
{
	char	*t_specif;

	t_specif = ft_strnew(16);
	if (t_specif == NULL)
		return (NULL);
	t_specif[0] = 's';
	t_specif[1] = 'S';
	t_specif[2] = 'p';
	t_specif[3] = 'd';
	t_specif[4] = 'D';
	t_specif[5] = 'i';
	t_specif[6] = 'o';
	t_specif[7] = 'O';
	t_specif[8] = 'u';
	t_specif[9] = 'U';
	t_specif[10] = 'x';
	t_specif[11] = 'X';
	t_specif[12] = 'c';
	t_specif[13] = 'C';
	t_specif[14] = '%';
	return (t_specif);
}
