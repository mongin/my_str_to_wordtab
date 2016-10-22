/*
** alexis.mongin@epitech.eu
** Welcome to the best my_str_to_wordtab ever!
** It's great because it call malloc only once;
** So you can show of in all of your projects if you dont mind -42!
** you just have to do free(wordtab) for getting rid of it.
** I know the code is ugly but tell that to the norm.
*/

#include <stdlib.h>

unsigned	is_separator(char c, char *seps)
{
  while (*seps)
    {
      if (c == *seps)
	return (1);
      seps++;
    }
  return (0);
}
 
unsigned	count_required_chars(char *str, unsigned *nb_words, char *seps)
{
  unsigned	i;
  unsigned	count;
  unsigned	nb_words_tmp;

  count = 0;
  i = 0;
  nb_words_tmp = 1;
  while (is_separator(str[i], seps))
    i++;
  while (str[i])
    {
      if (is_separator(str[i], seps))
	{
	  while (is_separator(str[i], seps))
	    i++;
	  if (str[i] != 0)
	    nb_words_tmp++;
	}
      else
	i++;
      count++;   
    }
  *nb_words = nb_words_tmp;
  return (count + 1);
}

void		fill_wordtab(char **wt, char *words, char *str, char *seps)
{
  unsigned	wt_i;
  unsigned	words_i;
  unsigned	str_i;

  wt_i = 0;
  words_i = 0;
  str_i = 0;
  while (is_separator(str[str_i], seps))
    str_i++;
  while (str[str_i])
    {
      while (is_separator(str[str_i], seps))
	str_i++;
      if (!is_separator(str[str_i], seps) && str[str_i])
	{
	  wt[wt_i] = words + words_i;
	  wt_i++;
	  while (!is_separator(str[str_i], seps) && str[str_i])
	    words[words_i++] = str[str_i++];
	  words[words_i] = 0;
	  words_i++;
	}
    }
  wt[wt_i] = NULL;
}

void		my_show_wordtab(char **wt)
{
  unsigned	i;

  i = 0;
  while (wt[i])
    {
      printf("%s\n", wt[i]);
      i++;
    }
}

char		**my_str_to_wordtab(char *str, char *separators)
{
  unsigned      count;
  unsigned	nb_words;
  char		*wordtab;

  if (!str)
    return (NULL);
  count = count_required_chars(str, &nb_words, separators);
  if (count == 0)
    return (NULL);
  if (!(wordtab = malloc((sizeof(char*) * (nb_words + 1)) + count)))
    return (NULL);
  fill_wordtab((char **)wordtab,
	       wordtab + (sizeof(char*) * (nb_words + 1)), str, separators);
  return ((char **)wordtab);
}
