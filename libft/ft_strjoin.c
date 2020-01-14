/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 10:38:29 by agarzon-          #+#    #+#             */
/*   Updated: 2019/11/29 10:23:03 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	total;
	int		l;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	total = ((ft_strlen(s1)) + (ft_strlen(s2)) + 1);
	new = (char*)malloc(sizeof(char) * total);
	if (new == 0)
		return (NULL);
	l = 0;
	while (total > 0)
	{
		if (*s1 != '\0')
			new[l++] = *s1++;
		if (*s1 == '\0')
		{
			while (*s2 != '\0')
				new[l++] = *s2++;
			break ;
		}
		total--;
	}
	new[l] = '\0';
	return (new);
}
