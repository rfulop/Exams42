#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int is_space(char c)
{
	return (c == ' ' || c == '\t' ? 1 : 0);
}

void rostring(char *str)
{
	int first;
	int end;
	int i = 0;
	int word = -1;

	while (str[i])
	{
		if (str[i] && !is_space(str[i]))
		{
			first = i;
			while (str[i] && !is_space(str[i]))
				++i;
			end = i;
			break;
		}
		++i;
	}
	while (str[i])
	{
		if (str[i] && !is_space(str[i]))
		{
			if (word != -1)
				write(1, " ", 1);
			word = i;
			while (str[i] && !is_space(str[i]))
				++i;
			write(1, &str[word], i - word);
			continue;
		}
		++i;
	}
	if (word != -1)
		write(1, " ", 1);
	write(1, &str[first], end - first);
}

int main(int argc, char **argv)
{
	if (argc > 1)
		rostring(argv[1]);
	write(1, "\n", 1);
	return 0;
}
