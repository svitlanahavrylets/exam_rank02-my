/*

Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);

*/

#include <stdlib.h>

int is_delimiter(char c)
{
    if (c == 9 || c == 10 || c == 32)
        return (1);
    return (0);
}

int	count_words(char *str)
{
	int	count = 0;
	int	i = 0;

	while (str[i])
	{
		while (str[i] && is_delimiter(str[i]))
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && !is_delimiter(str[i]))
				i++;
		}
	}
	return (count);
}

char	**ft_split(char *str)
{
	char	**result;
	int		i = 0;
	int		k = 0;
    int		j;
	int		word_len;

	result = (char **)malloc(sizeof(char *) * (count_words(str) + 1));
	if (!result)
		return (NULL);

	while (str[i])
	{
		while (str[i] && is_delimiter(str[i]))
			i++;
		if (str[i])
		{
			word_len = 0;
			while (str[i + word_len] && !is_delimiter(str[i + word_len]))
				word_len++;
			result[k] = (char *)malloc(sizeof(char) * (word_len + 1));
			if (!result[k])
				return (NULL);
			j = 0;
			while (j < word_len)
            {
                result[k][j] = str[i];
                i++;
                j++;
            }
			result[k][j] = '\0';
			k++;
		}
	}
	result[k] = NULL; 
	return (result);
}