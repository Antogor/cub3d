/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:16:03 by agarzon-          #+#    #+#             */
/*   Updated: 2019/11/27 11:43:54 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *l;
	unsigned char *q;

	l = (unsigned char*)s1;
	q = (unsigned char*)s2;
	while (n > 0)
	{
		if (*l != *q)
			return ((int)(*l - *q));
		l++;
		q++;
		n--;
	}
	return (0);
}
