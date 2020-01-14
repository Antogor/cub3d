/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:14:08 by agarzon-          #+#    #+#             */
/*   Updated: 2019/11/27 11:41:03 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	l;
	size_t			q;

	if (!s)
		return (NULL);
	q = ft_strlen(s) + 1;
	new = (char*)malloc(sizeof(char) * q);
	if (new == 0)
		return (NULL);
	l = 0;
	while (s[l] != '\0')
	{
		new[l] = f(l, s[l]);
		l++;
	}
	new[l] = '\0';
	return (new);
}
