#include <unistd.h>

void printhex(unsigned char c)
{
  char tab[16] = "0123456789abcdef";
  write(1, &tab[c / 16], 1);
  write(1, &tab[c % 16], 1);
}

void printascii(unsigned char *str, size_t j, size_t size)
{
  size_t i;

  while (j % 16)
  {
	  write(1, "  ", 2);
	  ++j;
	  if (j % 2)
		write(1, " ", 1);
  }
  write(1, " ", 1);
  i = j - 16;
  while (i < j && i < size)
  {
    if (str[i] > 31 && str[i] < 127)
      write(1, &str[i], 1);
    else
      write(1, ".", 1);
    ++i;
  }
}

void print_memory(const void *addr, size_t size)
{
  size_t i;
  size_t j;
  unsigned char *str;

  str = (unsigned char *)addr;
  i = 0;
  j = 1;
  while (i < size)
  {
    printhex(str[i]);
    if (i % 2 && (j % 16) && (i + 1 <  size))
      write(1, " ", 1);
	if (j % 16 == 0 || i + 1 == size)
	{
		 printascii(str, j, size);
		write(1, "\n", 1);
	}
    ++j;
    ++i;
  }
}
