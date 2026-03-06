/*

Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int	    is_power_of_2(unsigned int n);

*/
#include <stdio.h>

int	is_power_of_2(unsigned int n)
{

	if (n == 1)
		return (1);
	while (n > 1)
	{
		if (n % 2 == 0)
		{
			if (n == 2)
				return (1);
			n = n / 2;
		}
		else
			return (0);

	}
	return (0);
}

int	main(void)
{

	printf("result: %d\n", is_power_of_2(1));
	printf("result: %d\n", is_power_of_2(2));
	printf("result: %d\n", is_power_of_2(3));
	printf("result: %d\n", is_power_of_2(4));
	printf("result: %d\n", is_power_of_2(5));
	printf("result: %d\n", is_power_of_2(6));
	printf("result: %d\n", is_power_of_2(7));
	printf("result: %d\n", is_power_of_2(8));
	printf("result: %d\n", is_power_of_2(10));
	printf("result: %d\n", is_power_of_2(0));
	return (0);
}
