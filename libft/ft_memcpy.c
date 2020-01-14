/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:12:52 by agarzon-          #+#    #+#             */
/*   Updated: 2019/11/27 11:44:09 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned	char *l;
	const		char *q;

	l = (unsigned char*)dst;
	q = (const char*)src;
	if (l == NULL && q == NULL)
		return (0);
	while (n > 0)
	{
		*(l++) = *(q++);
		n--;
	}
	return (dst);
}
