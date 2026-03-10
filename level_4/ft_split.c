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

# include <stdio.h>
#include <stdlib.h>

int	is_delimiter(char c)
{
	if (c == 9 || c == 10 || c == 32 )
		return (1);
	return (0);
}

int	count_word(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && is_delimiter(str[i]) == 1)
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && is_delimiter(str[i]) == 0)
				i++;
		}
	}
	return (count);
}

char	**ft_split(char *str)
{
	char	**result;
	int		word_len;
	int		i;
	int		k;
	int		j;

	i = 0;
	printf("count_world: %d\n", count_word(str));
	result = malloc(sizeof(char*) * (count_word(str) + 1));
	if (!result)
		return (NULL);
	j = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] && is_delimiter(str[i]) == 1)
			i++;
		if (str[i])
		{
			word_len = 0;
			while (str[i + word_len] && is_delimiter(str[i + word_len]) == 0)
				word_len++;
			result[k] = malloc(sizeof(char) * (word_len + 1));
			if (!result[k])
				return (NULL);
			j = 0;
			while (j < word_len)
			{
				result[k][j] = str[i];
				j++;
				i++;

			}
			result[k][j] = '\0';
			k++;
		}
	}
	result[k] = NULL;
	return (result);
}


int	main(void)
{
	char **res;
	int i;

	// res = ft_split("   ");
	// res = ft_split("");
	res = ft_split("13kj kfh !  vf  B");
	// res = ft_split(" hi  ");
	if (!res)
		return (0);
	i = 0;
	while (res[i])
	{
		printf("word: %s\n", res[i]);
		free(res[i]);
		i++;
	}
	free(res);
	return (0);
}