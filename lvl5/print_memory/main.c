#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void print_memory(const void *addr, size_t size);

int main()
{
	int tab[0];
///	int tab[10] = {0, 23, 150, 255, 12, 16, 21, 42};
//	char tab[0] = {1, 112, -1, 12, 23, 150, 255, 12, 16, 21, 42};
	print_memory(tab, sizeof(tab));
	return 0;
}
