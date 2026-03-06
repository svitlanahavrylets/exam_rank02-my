/*

Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$

*/
#include <stdio.h>
#include <unistd.h>

// #define HEX_LOW "0123456789abcdef"

void	putnmb_base(int n)
{
	char	*hex;

	hex = "123456789abcdef";
	if (n >= 16)
		putnmb_base(n / 16);
	write(1, &hex[n % 16], 1);
}

int	ft_atoi(char *av)
{
	int	result;

	result = 0;
	while (*av == ' ' || *av >= 9 && *av <= 13)
		av++;
	if (*av == '+')
		av++;
	while (*av >= '0' && *av <= '9')
	{
		result = result * 10 + *av - '0';
		av++;
	}
	return (result);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		putnmb_base((unsigned int)ft_atoi(av[1]));
	}
	write(1, "\n", 1);
	return (0);
}
