#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_env
{
  int total;
  int sizeIntTab;
}     t_env;

int ft_strlen(char *str)
{
  int a;

  a = 0;
  while (str[a])
    ++a;
  return (a);
}

char *ft_sign_tab(char *str)
{
  int i;
  int j;
  int size;
  char *signTab;

  i = 0;
  size = 0;
  while (str[i])
  {
    if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' ||
        str[i] == '%')
        ++size;
    ++i;
  }
  signTab = (char*)malloc(sizeof(char) * size + 1);
  signTab[size] = '\0';
  i = 0;
  j = 0;
  while (str[i])
  {
    if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' ||
        str[i] == '%')
        {
          signTab[j] = str[i];
          ++j;
        }
    ++i;
  }
  return signTab;
}

int putnb(char *tab, int *i)
{
  int res;

  res = atoi(&tab[*i]);
  ++*i;
  while (tab[*i] >= '0' && tab[*i] <= '9')
    ++*i;
  printf("res = %d\n", res);
  return res;
}

int *ft_int_tab(t_env *env, char *str)
{
  int i;
  int j;
  int *intTab;

  i = 0;
  while (str[i])
  {
    if ((str[i] >= '0' && str[i] <= '9'))
        ++env->sizeIntTab;
    ++i;
  }
  intTab = (int*)malloc(sizeof(int) * env->sizeIntTab + 1);
  intTab[env->sizeIntTab] = '\0';
  i = 0;
  j = 0;
  while (str[i])
  {
//    printf("atoi = %d\n", atoi(&str[i]));
    if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-' && (str[i+1] >= '0' && str[i+1] <= '9'))
        {
          intTab[j] = putnb(str, &i);
          ++j;
        }
    ++i;
  }
  return intTab;
}

int *moove(t_env *env, int *tab, int result)
{
  int i;
  int *res;

  res = (int*)malloc(sizeof(int) * env->sizeIntTab);
  res[env->sizeIntTab] = '\0';
  res[0] = result;
  i = 1;
  while (i < env->sizeIntTab - 1)
  {
    res[i] = tab[i + 1];
    ++i;
  }
  --env->sizeIntTab;
  free(tab);
  return (res);
}

int *op(t_env *env, int *tab, char sign)
{
  int total;

  total = 0;
  if (sign == '+')
    total = tab[0] + tab[1];
  else if (sign == '-')
    total = tab[0] - tab[1];
  else if (sign == '*')
    total = tab[0] * tab[1];
  else if (sign == '/')
    total = tab[0] / tab[1];
  else if (sign == '%')
    total = tab[0] % tab[1];
  tab = moove(env, tab, total);
  env->total = total;
  printf("total = %d\n", total);
  return tab;
}

void calc(t_env *env, char *str)
{
  int i;
  int size;
  char *signTab;
  int *intTab;

  signTab = ft_sign_tab(str);
  intTab = ft_int_tab(env, str);
  i = 0;
  size = ft_strlen(signTab);
  while (i < size)
  {
    intTab = op(env, intTab, signTab[i]);
    ++i;
  }
}

int main(int argc, char **argv)
{

  t_env env;
  if (argc < 2)
    write(1, "Error\n", 6);
  else
  {
    env.total = 0;
    calc(&env, argv[1]);
    printf("size = %d\n", env.sizeIntTab);
    if (env.sizeIntTab == 1)
      printf("%d\n", env.total);
    else
      write(1, "Error\n", 6);
  }
  return (0);
}
