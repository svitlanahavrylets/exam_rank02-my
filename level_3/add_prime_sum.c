/*

Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>

*/

#include <stdio.h>
#include <unistd.h>

int	is_prime(int n)
{
	int	i;

	if (n <= 1)
		return (0);
	i = 2;
	if (i * i <= n)
	{
		if (n % i == 0)
			return (0);
	}
	return (1);
}

int	atoi(char *s)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (s[i] == ' ')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + s[i] - '0';
		i++;
	}
	return (result);
}

void	putnmb(int sum)
{
	char	n;

	if (sum >= 10)
		putnmb(sum / 10);
	while (n < sum)
	{
		n = sum % 10 + '0'; 
		write(1, &n, 1);
	}
}

int	main(int ac, char **av)
{
	int	n;
	int	sum;

	if (ac == 2)
	{
		n = atoi(av[1]);
		printf("n %d\n", n);
		sum = 0;
		while (n > 1)
		{
			if (is_prime(n))
				sum += n;
			n--;
		}
		putnmb(sum);
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}
