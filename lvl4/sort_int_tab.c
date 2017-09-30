void sort_int_tab(int *tab, unsigned int size)
{
  int tmp;
  unsigned int i;

  i = 0;
  if (size)
  {
    while (i < size -1)
    {
      if (tab[i] > tab[i + 1])
      {
        tmp = tab[i];
        tab[i] = tab[i + 1];
        tab[i + 1] = tmp;
        i = 0;
      }
      else
        ++i;
    }
  }
}
