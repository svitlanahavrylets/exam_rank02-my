// Assignment name	: ft_strspn
// Expected files	: ft_strspn.c
// Allowed functions: None
// ---------------------------------------------------------------

// Reproduce exactly the behavior of the strspn function 
// (man strspn).

// The function should be prototyped as follows:

// size_t	ft_strspn(const char *s, const char *accept);

#include <stdio.h>
#include <string.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t i;
	size_t j;
	int	is_the_same;

	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		is_the_same = 0;
		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
				is_the_same = 1;
			j++;
		}
		if (is_the_same == 0)
				return(i);
		i++;
	}
	return (i);
}

int	main(void)
{
	char	arr[] = "123abc45";
	char	substring[] = "f1234567890a";
	int		len_of_substr;
	int		len_of_substr2;

	len_of_substr = ft_strspn(arr, substring);
	len_of_substr2 = strspn(arr, substring);
	printf("in ft_strspn => i = %d\n", len_of_substr);
	printf("in strspn => i = %d\n", len_of_substr2);

	return (1);
}