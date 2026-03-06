// Assignment name  : ft_strdup
// Expected files   : ft_strdup.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Reproduce the behavior of the function strdup (man strdup).

// Your function must be declared as follows:

// char    *ft_strdup(char *src);

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char    *ft_strdup(char *src)
{
	char	*new_src;
	int		len;
	int 	i;

	i = 0;
	while (src[len] !='\0')
		len++;
	new_src = malloc(sizeof(char) * len + 1);
	if (!new_src)
		return(NULL);
	while (src[i] != '\0')
	{
		new_src[i] = src[i];
		i++;
	}
	new_src[i] = 0;
	return (new_src);
}

int main(void)
{
	char *a;

	a = "HelloWorld";
	printf("%s\n", ft_strdup(a));
	return (1);
}