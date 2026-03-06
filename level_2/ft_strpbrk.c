/*

Assignment name	: ft_strpbrk
Expected files	: ft_strpbrk.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:

char	*ft_strpbrk(const char *s1, const char *s2);

*/
#include <stdio.h>
#include <string.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int i;
	int k;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[i] != '\0')
	{
		k = 0;
		while (s2[k] != '\0')
		{
			if (s1[i] == s2[k])
				return ((char *)&s1[i]);
			k++;
		}
		i++;
	}
	return (NULL);
}

int	main(void)
{
	char	*s1 = "Hello";
	char	*s2 = "doH";
	const char	*res;
	const char	*res2;

	res = ft_strpbrk(s1, s2);
	printf("result: %s\n", res);

	res2 = strpbrk(s1, s2);
	printf("result2: %s\n", res2);

	return (0);

}
