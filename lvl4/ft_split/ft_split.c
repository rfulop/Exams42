/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 23:49:11 by rfulop            #+#    #+#             */
/*   Updated: 2017/10/12 01:05:31 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>


int is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' ? 1 : 0);
}

int count_word(char *str)
{
	int i = 0;
	int word = 0;

	while (str[i])
	{
		if (str[i] && !is_space(str[i]))
		{
			++word;
			while (str[i] && !is_space(str[i]))
				++i;
		}
		else
			++i;
	}
	return word;
}

int count_letters(char *str)
{
	int i = 0;

	while (str[i] && !is_space(str[i]))
		++i;
	return i;
}

char **ft_split(char *str)
{
	char **ret;
	int words;
	int letters;
	int k;
	int i = 0;
	int j = 0;

	words = count_word(str);
	ret = (char**)malloc(sizeof(char*) * words + 1);
	ret[words] = NULL;
	while (str[i])
	{
		while (str[i] && is_space(str[i]))
			++i;
		letters = count_letters(str + i);
		if (!letters)
			break;
		ret[j] = (char*)malloc(sizeof(char) * letters + 1);
		ret[j][letters] = '\0';
		k = 0;
		while (k < letters)
		{
			ret[j][k] = str[i + k];
			++k;
		}
		i += letters;
		++j;
	}
	return ret;
}

int main(int argc, char **argv)
{
	char **test;
	if (argc > 1)
		test = ft_split(argv[1]);
	for (int i = 0; test[i]; ++i)
		printf("%d - '%s'\n", i, test[i]);
	return 0;
}
