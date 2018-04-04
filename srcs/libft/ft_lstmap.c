/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 10:29:02 by vbaudron          #+#    #+#             */
/*   Updated: 2016/11/30 15:33:51 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*dst;

	dst = NULL;
	if (lst)
	{
		dst = malloc(sizeof(t_list));
		if (dst == NULL)
			return (0);
		dst = f(lst);
		if (lst->next == NULL)
		{
			dst->next = NULL;
			return (dst);
		}
		dst->next = ft_lstmap(lst->next, f);
	}
	return (dst);
}
