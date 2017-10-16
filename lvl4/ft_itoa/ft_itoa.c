/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 23:58:47 by rfulop            #+#    #+#             */
/*   Updated: 2017/10/17 00:04:53 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int ft_size(int nbr)
{
	int size = 1;
	while (nbr >= 10)
	{
		nbr /= 10;
		++size;
	}
	return size;
}

char *ft_itoa(int nbr)
{
	int sign = 0;
	int i;
	char *res;

	if (nbr == -2147483648)
	{
		res = (char*)malloc(sizeof(char) * 12);
		res = "-2147483648";
	}
	else
	{
		if (nbr < 0)
		{
			++sign;
			nbr *= -1;
		}
		i = ft_size(nbr);
		res = (char*)malloc(sizeof(char) * (i + sign + 1));
		res[sign + i] = '\0';
		if (sign)
			res[0] = '-';
		while (i > 0)
		{
			res[i + sign - 1] = nbr % 10 + '0';
			nbr /= 10;
			--i;
		}
	}
	return res;
}
