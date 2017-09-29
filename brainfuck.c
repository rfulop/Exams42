#include <unistd.h>

char *loop(char *s, int way)
{
  int a;

  a = 0;
  while (1)
  {
    if (*s == '[')
      ++a;
    else if (*s == ']')
      --a;
    if (!a)
      return s;
    s += way;
  }
  return NULL;
}

void brainfuck(char *s, char *d)
{
  while (*s)
  {
    if (*s == '+')
      ++(*d);
    else if (*s == '-')
      --(*d);
    else if (*s == '>')
      ++d;
    else if (*s == '<')
      --d;
    else if (*s == '.')
      write(1, d, 1);
    else if (*s == '[' && !*d)
      s = loop(s, 1);
    else if (*s == ']' && *d)
      s = loop(s, -1);
    ++s;
  }
}

int main(int argc, char **argv)
{
  int a;
  char d[2048];

  if (argc < 2)
    write(1, "\n", 1);
  else
  {
    a = 0;
    while (a < 2048)
      d[a++] = 0;
    brainfuck(argv[1], d);
  }
  return 0;
}
