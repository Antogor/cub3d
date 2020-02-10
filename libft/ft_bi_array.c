/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:58:02 by agarzon-          #+#    #+#             */
/*   Updated: 2020/02/10 12:03:39 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int **ft_bi_array(int **array, int nrows, int ncolumns)
{
    int i;

	i = 0;
    if(!(array = malloc(nrows * sizeof(int *))))
		return (NULL);
    while (i < nrows)
    {
    	if(!(array[i] = malloc(ncolumns * sizeof(int))))
			return (NULL);
		i++;
    }
	return(array);
}
