/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_bi_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:06:23 by agarzon-          #+#    #+#             */
/*   Updated: 2020/02/10 12:07:00 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	**ft_fill_bi_array(int **array, int rows, int columns, int filled)
{
	int l;
	int q;

	l = 0;
	q = 0;
	while(l < rows)
	{
		q = 0;
		while(q < columns)
		{
			array[l][q] = filled;
			q++;
		}
		l++;
	}
	return (array);
}
