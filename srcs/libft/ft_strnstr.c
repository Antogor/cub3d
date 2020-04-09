/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:32:18 by agarzon-          #+#    #+#             */
/*   Updated: 2019/11/15 17:34:16 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack,
	const char *needle, size_t len)
{
	size_t	l;
	size_t	q;

	l = 0;
	q = 0;
	if (needle[l] == '\0')
		return ((char*)haystack);
	while (haystack[l] != '\0' && l < len)
	{
		if (haystack[l] == needle[0])
		{
			q = 1;
			while (needle[q] != '\0' && haystack[l + q] == needle[q]
			&& l + q < len)
				q++;
			if (needle[q] == '\0')
				return ((char*)(haystack + l));
		}
		l++;
	}
	return (NULL);
}
