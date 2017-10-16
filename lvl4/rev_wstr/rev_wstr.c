/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 22:32:53 by rfulop            #+#    #+#             */
/*   Updated: 2017/10/16 22:40:01 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int is_space(char c)
{
	return (c == ' ' || c == '\t' ? 1 : 0);
}

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		++i;
	return i;
}


void rev(char *str)
{
	int i;
	int len = ft_strlen(str);

	while (len)
	{
		i = len;
		while (str[i - 1] && !is_space(str[i - 1]))
			--i;
		write(1, &str[i], len - i);
		if (i)
		{
			write(1, " ", 1);
			--i;
		}
		len = i;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		rev(argv[1]);
	write(1, "\n", 1);
	return 0;
}
