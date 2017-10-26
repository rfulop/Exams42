/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 10:02:09 by exam              #+#    #+#             */
/*   Updated: 2017/10/26 03:49:53 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int is_open(char c)
{
	return (c == '(' || c == '{' || c == '[' ? 1 : 0);
}

int is_close(char c)
{
	return (c == ')' || c == '}' || c == ']' ? 1 : 0);
}

int find(char *str, char c)
{
	int i = 0;

	while (str[i])
	{
		if ((c == '(' && str[i] == ')') || (c == '{' && str[i] == '}') ||
			(c == '[' && str[i] == ']'))
		{
			str[i] = 1;
			return 1;
		}
		else if (is_open(str[i]))
		{
			if ((find(str + i + 1, str[i])))
				str[i] = 1;
			else
				return 0;
		}
		else if (is_close(str[i]) && str[i] != c)
			return 0;
		++i;
	}
	return 0;
}

int check(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (is_close(str[i]))
			return 0;
		++i;
	}
	return 1;
}

int brackets(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (is_open(str[i]))
		{
			if (!(find(str + i + 1, str[i])))
				return 0;
			else
				str[i] = 1;
		}
		++i;
	}
	return 1;
}

int main(int argc, char **argv)
{
	int i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			if (!(brackets(argv[i])) || !check(argv[i]))
				write(1, "Error\n", 6);
			else
					write(1, "OK\n", 3);
			++i;
		}
	}
	else
		write(1, "\n", 1);
	return 0;
}
