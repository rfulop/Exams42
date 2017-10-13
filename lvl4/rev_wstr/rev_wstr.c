#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		++i;
	return i;
}

int is_space(char c)
{
	return (c == ' ' || c == '\t' ? 1 : 0);
}

void rev(char *str)
{
	int len = ft_strlen(str);
	int i = len;

	while (i)
	{
		while (str[i - 1] && !is_space(str[i - 1]))
			--i;
		write(1, &str[i], len - i);
		if (is_space(str[i - 1]))
		{
			--i;
			write(1, " ", 1);
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
