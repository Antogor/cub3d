/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bi_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:58:02 by agarzon-          #+#    #+#             */
/*   Updated: 2020/02/19 18:45:17 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char **ft_bi_array(int nrows, int ncolumns)
{
    int		i;
	char	**array;

	i = 0;
    if(!(array = malloc(nrows * sizeof(char *))))
		return (NULL);
    while (i < nrows)
    {
    	if(!(array[i] = malloc(ncolumns * sizeof(char))))
			return (NULL);
		i++;
    }
	return(array);
}
