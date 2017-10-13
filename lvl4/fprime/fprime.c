#include <stdio.h>
#include <stdlib.h>

void fprime(int nb)
{
	int i = 2;

	if (nb == 1)
		printf("1");
	else
	{
		while (nb != 1)
		{
			if (nb % i == 0)
			{
				printf("%d", i);
				nb /= i;
				if (nb != 1)
					printf("*");
			}
			else
				++i;
		}
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		fprime(atoi(argv[1]));
	printf("\n");
	return 0;
}
