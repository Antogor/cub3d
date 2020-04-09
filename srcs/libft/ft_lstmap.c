/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:32:42 by agarzon-          #+#    #+#             */
/*   Updated: 2019/11/28 11:07:52 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list *new;
	t_list *aux;

	if (!lst)
		return (NULL);
	aux = ft_lstnew(f(lst->content));
	new = aux;
	while (lst->next != NULL)
	{
		lst = lst->next;
		if (!(aux->next = ft_lstnew(f(lst->content))))
		{
			del(aux->next);
			free(aux->next);
			return (NULL);
		}
		aux = aux->next;
	}
	return (new);
}
