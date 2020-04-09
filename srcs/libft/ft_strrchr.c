/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:45:44 by agarzon-          #+#    #+#             */
/*   Updated: 2019/11/27 11:41:23 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *last_pos;

	last_pos = NULL;
	while (*s != '\0')
	{
		if (*s == c)
			last_pos = s;
		s++;
	}
	if (last_pos)
		return ((char*)last_pos);
	if (c == '\0')
		return ((char*)s);
	return (NULL);
}
