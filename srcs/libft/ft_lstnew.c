/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 10:51:27 by vbaudron          #+#    #+#             */
/*   Updated: 2016/12/05 13:04:45 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *tmp;

	tmp = malloc(sizeof(t_list));
	if (tmp == NULL)
		return (NULL);
	if (content != NULL)
	{
		tmp->content = malloc(sizeof(char) * content_size);
		if (tmp->content == NULL)
			return (0);
		tmp->content = ft_memcpy(tmp->content, content, content_size);
		tmp->content_size = content_size;
		tmp->next = NULL;
	}
	if (content == NULL)
	{
		tmp->content = NULL;
		tmp->content_size = 0;
		tmp->next = NULL;
	}
	return (tmp);
}
