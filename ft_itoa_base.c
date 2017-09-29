#include <stdlib.h>
#include <stdio.h>

int convhex(int nb)
{
    if (nb >= 10)
      return (nb - 10 + 'a');
    else
      return (nb + '0');
}

int count_size(int nb, int len)
{
  int size;

  size = 0;
  while (nb >= len)
  {
    nb = nb / len;
    ++size;
  }
  return (size);
}

char *ft_itoa_base(int value, int base)
{
  int sign;
  int size;
  char *str;

  sign = 0;
  if (value < 0)
  {
    value *= -1;
    ++sign;
  }
  size = count_size(value, base);
  if (!(str = (char*)malloc(sizeof(char) * (size + sign + 1))))
    return (NULL);
  str[size + sign] = '\0';
  if (sign)
    str[0] = '-';
  while (size >= 0)
  {
    str[size + sign] = convhex(value % base);
    value /= base;
    --size;
  }
  return (str);
}

int main()
{
  int value = 142;
  int base = 4;
  printf("str = %s\n", ft_itoa_base(value, base));
  return 0;
}
