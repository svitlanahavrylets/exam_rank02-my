/*

Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.

*/
#include <stdio.h>

int	max(int *tab, unsigned int len)
{
	int	i;
	int	tmp_max;

	if (len == 0)
		return (0);
	tmp_max = tab[0];
	i = 0;
	while (i < len)
	{
		if (tab[i] > tmp_max)
			tmp_max = tab[i];
		i++;
	}
	return (tmp_max);

}

int	main(void)
{
	int	tab[4] = {23575, 4567, 1, 878};
	int		max_number_is;

	max_number_is = max(tab, 4);
	printf("max_number_is: %d", max_number_is);
	return (0);
}
