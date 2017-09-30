#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
  char *ptr;

  ptr = str;
  while (*ptr)
    ++ptr;
  return (ptr - str);
}

char *first_word(char *str)
{
  int i;
  int size;
  char *word;

  i = 0;
  size = 0;
  while (str[i] == ' ' || str[i] == '\t')
    ++i;
  while (str[i + size] != ' ' && str[i + size] != '\t')
    ++size;
  word = (char*)malloc(sizeof(char) * size + 1);
  word[size] = '\0';
  size = 0;
  while (str[i] != ' ' && str[i] != '\t')
  {
    word[size] = str[i];
    ++i;
    ++size;
  }
  return word;
}

void printsent(char *str, int i)
{
  int tmp;

  tmp = i;
  while (str[i])
  {
    if ((str[i]) && str[i] == ' ' || str[i] == '\t')
    {
      write(1, " ", 1);
      while ((str[i]) && str[i] == ' ' || str[i] == '\t')
        ++i;
    }
    else
    {
      write(1, &str[i], 1);
      ++i;
    }
  }
  if (i > tmp)
    if (str[ft_strlen(str) - 1] != ' ' && str[ft_strlen(str) - 1] != '\t')
      write(1, " ", 1);
}

void rotstring(char *str)
{
  int i;
  char *word;

  word = first_word(str);
  i = 0;
  while ((str[i]) && str[i] == ' ' || str[i] == '\t')
    ++i;
  while ((str[i]) && str[i] != ' ' && str[i] != '\t')
    ++i;
  while ((str[i]) && str[i] == ' ' || str[i] == '\t')
    ++i;
  if (ft_strlen(word) != ft_strlen(str))
    printsent(str, i);
  write(1, word, ft_strlen(word));
  write(1, "\n", 1);
}

int main(int argc, char **argv)
{
  if (argc != 2)
    write(1, "\n", 1);
  else
    rotstring(argv[1]);
  return (0);
}
