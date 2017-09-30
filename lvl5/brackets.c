#include <unistd.h>

int open(char *str, int a, char c)
{
  while (str[a])
  {
    if (str[a] == '(' || str[a] == '{' || str[a] == '[')
    {
        if (open(str, a + 1, str[a]))
          str[a] = '.';
        else
          return (0);
    }
    else if ((str[a] == ')' && c == '(') || (str[a] == '}' && c  == '{') ||
        (str[a] == ']' && c == '['))
    {
      str[a] = '.';
      return (1);
    }
    else if (str[a] == ')' || str[a] == '}' || str[a] == ']')
      return (0);
    ++a;
  }
  return (0);
}

int brackets(char *str)
{
  int a;

  a = 0;
  while (str[a])
  {
    if (str[a] == '(' || str[a] == '{' || str[a] == '[')
    {
      if (open(str, a + 1, str[a]))
        str[a] = '.';
      else
        return (0);
    }
    ++a;
  }
  return (1);
}

int main(int argc, char **argv)
{
  int a;

  if (argc < 2)
    write(1, "\n", 1);
  else
  {
    a = 1;
    while (a < argc)
    {
      if (brackets(argv[a]))
        write(1, "OK\n", 3);
      else
        write(1, "Error\n", 6);
      ++a;
    }
  }
  return (0);
}
