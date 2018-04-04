/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crea_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:29:06 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/27 12:49:13 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			find_gab(const char **format, int i, int k, char **save)
{
	if ((*format)[i - 1] && (*format)[i - 1] == '.')
		return (-1);
	k++;
	while ((*format)[i + k] >= '0' && (*format)[i + k] <= '9')
		k++;
	if ((*save = ft_strnew(k + 1)) == NULL)
		return (-2);
	k = 0;
	while ((*format)[i + k] >= '0' && (*format)[i + k] <= '9')
	{
		(*save)[k] = (*format)[i + k];
		k++;
	}
	return (k);
}

int			has_gab(const char **format, int i, int j, char **t_specif)
{
	int		k;
	char	*save;
	int		nb_gab;

	k = 0;
	save = NULL;
	nb_gab = -1;
	while ((*format)[i] != (*t_specif)[j])
	{
		if ((*format)[i] >= '1' && (*format)[i] <= '9')
		{
			if ((k = find_gab(format, i, k, &save)) == -1 || k == -2)
				return (k);
			nb_gab = ft_atoi(save);
			free(save);
			save = NULL;
			return (nb_gab);
		}
		i++;
	}
	return (nb_gab);
}

char		*has_modif(const char **format, int i, int j, char **t_specif)
{
	char	*modif;
	int		k;

	k = 0;
	if ((modif = ft_strnew(4)) == NULL)
		return (NULL);
	while ((*format)[i] != (*t_specif)[j] && k < 4)
	{
		if ((*format)[i] == 'h' || (*format)[i] == 'l' || (*format)[i] == 'j'
		|| (*format)[i] == 'z')
		{
			modif[k] = (*format)[i];
			k++;
		}
		i++;
	}
	return (&modif[0]);
}

void		finish_elem(t_struct *elem, char *t_specif, int j)
{
	elem->neg = 0;
	elem->todo_gab = 0;
	elem->ret = 0;
	elem->done_neg = 0;
	elem->todo_prec = elem->prec;
	elem->specif = t_specif[j];
}

t_struct	*crea_struct(t_struct *elem, const char **f, int i, char *t_specif)
{
	int	j;

	j = 0;
	elem = malloc(sizeof(t_struct));
	if (elem == NULL || (j = has_specif(f, i, &t_specif)) == -1)
		return (NULL);
	if ((elem->has_flag = has_flags(f, i, j, &t_specif)) == 1)
	{
		if ((elem->flags = what_flags(f, i, j, &t_specif)) == NULL)
			return (NULL);
	}
	if ((elem->prec = ft_struct_has_prec(f, i, j, &t_specif)) == -1)
	{
		elem->prec_null = 1;
		elem->prec = 0;
	}
	if ((elem->modif = has_modif(f, i, j, &t_specif)) == NULL)
		return (NULL);
	if ((elem->gab = has_gab(f, i, j, &t_specif)) == -2)
		return (NULL);
	finish_elem(elem, t_specif, j);
	free(t_specif);
	return (elem);
}
