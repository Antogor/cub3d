/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:38:04 by agarzon-          #+#    #+#             */
/*   Updated: 2019/11/06 13:24:40 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57)
		|| ((c >= 65 && c <= 90)
		|| (c >= 97 && c <= 122)))
		return (1);
	else
		return (0);
}