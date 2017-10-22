/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 00:59:55 by rfulop            #+#    #+#             */
/*   Updated: 2017/10/23 01:55:25 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int ft_size(int nb, int base)
{
	int size = 1;

	while (nb >= base)
	{
		nb /= base;
		++size;
	}
	return size;
}

char *ft_itoa_base(int value, int base)
{
	int sign = 0;
	int i;
	char *res;
	char *hex = "0123456789ABCDEF";

	if (value == -2147483648 && base == 10)
	{
		res = (char*)malloc(sizeof(char) * 12);
		res = "-2147483648";
		return res;
	}
	if (value == -2147483648)
		value = 2147483647;
	if (value < 0)
	{
		value *= -1;
		if (base == 10)
			++sign;
	}
	i = ft_size(value, base);
	res = (char*)malloc(sizeof(char) * i + sign + 1);
	res[sign + i] = '\0';
	if (sign)
		res[0] = '-';
	while (i)
	{
		res[sign + i - 1] = hex[value % base];
		value /= base;
		--i;
	}
	return res;
}
