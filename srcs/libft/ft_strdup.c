/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:50:03 by agarzon-          #+#    #+#             */
/*   Updated: 2019/11/27 11:35:28 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	x;
	size_t	l;

	x = ft_strlen(s1);
	l = 0;
	dup = (char*)malloc(sizeof(char) * (x + 1));
	if (dup == 0)
		return (NULL);
	while (s1[l] != '\0')
	{
		dup[l] = s1[l];
		l++;
	}
	dup[l] = '\0';
	return ((char*)dup);
}
