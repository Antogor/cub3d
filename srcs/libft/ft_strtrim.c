/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:38:38 by agarzon-          #+#    #+#             */
/*   Updated: 2019/11/27 16:30:55 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		cstart(char const *s1, char const *set)
{
	size_t	count_s;
	int		l;

	count_s = 0;
	while (*s1 != '\0')
	{
		l = 0;
		while (set[l] != '\0')
		{
			if (set[l] == *s1)
			{
				count_s++;
				break ;
			}
			l++;
		}
		if (set[l] == '\0')
			return (count_s);
		s1++;
	}
	return (count_s);
}

size_t		cend(char const *s1, char const *set)
{
	size_t	count_e;
	size_t	len;
	int		l;

	count_e = 0;
	len = ft_strlen(s1) - 1;
	while (len > 0)
	{
		l = 0;
		while (set[l] != '\0')
		{
			if (set[l] == s1[len])
			{
				count_e++;
				break ;
			}
			l++;
		}
		if (set[l] == '\0')
			return (count_e);
		len--;
	}
	return (count_e);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	size_t	start;
	size_t	end;
	int		l;
	size_t	len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = cstart(s1, set);
	end = cend(s1, set);
	len = ft_strlen(s1);
	l = 0;
	if (start == len)
	{
		new = ft_strdup("");
		return (new);
	}
	if (!(new = (char*)malloc(sizeof(char) * (len - (start + end)) + 1)))
		return (NULL);
	while (start < len - end)
		new[l++] = s1[start++];
	new[l] = '\0';
	return (new);
}
