#include <stdio.h>
#include <stdlib.h>

int isprime(int nb)
{
  int i;

  i = 1;
  if (nb == 1)
    return 0;
  while (i < nb)
  {
    if ((!(nb % i)) && (i != nb) && (i != 1))
    {
      return 0;
    }
    ++i;
  }
  return 1;
}

void fprime(int nb)
{
  int i;
  int tmp;

  tmp = nb;
  i = 1;
  if (isprime(nb) || nb == 1)
    printf("%d", nb);
  else
  {
    while (i <= nb && tmp > 1)
    {
      if (isprime(i) && (!(tmp % i)))
      {
        tmp /= i;
        printf("%d", i);
        if (tmp > 1)
          printf("*");
      }
      else
        ++i;
    }
  }
  printf("\n");
}

int main(int argc, char **argv)
{
  if (argc != 2)
    printf("\n");
  else
    fprime(atoi(argv[1]));
  return 0;
}
