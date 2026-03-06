// Assignment name	: ft_strcspn
// Expected files	: ft_strcspn.c
// Allowed functions: None
// ---------------------------------------------------------------

// Reproduce exactly the behavior of the function strcspn
// (man strcspn).

// The function should be prototyped as follows:

// size_t	ft_strcspn(const char *s, const char *reject);

#include <stddef.h>
#include <stdio.h>
#include <string.h>


size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (reject[j] != '\0' )
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

int	main(void)
{
	char	arr[] = "HelloWorld";
	char	substring[] = "12345H";
	int		len_of_substr;
	int		len_of_substr2;

	len_of_substr = ft_strcspn(arr, substring);
	len_of_substr2 = strcspn(arr, substring);
	printf("in ft_strcspn => i = %d\n", len_of_substr);
	printf("in strcspn => i = %d\n", len_of_substr2);

	return (1);
}
