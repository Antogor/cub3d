/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:08:05 by agarzon-          #+#    #+#             */
/*   Updated: 2019/11/28 14:29:15 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *aux;

	aux = *lst;
	if (aux == NULL)
		*lst = new;
	else
	{
		while (aux->next)
			aux = aux->next;
		aux->next = new;
		new->next = NULL;
	}
}
