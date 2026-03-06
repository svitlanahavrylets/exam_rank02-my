/*

Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);

*/
#include <stdio.h>

int	get_value(char str)
{
	if (str >= '0' && str <= '9')
		return (str - '0');
	if (str >= 'a' && str <= 'f')
		return (str - 'a' + 10);
	if (str >= 'A' && str <= 'F')
		return (str - 'A' + 10);
	return (-1);
}


int	ft_atoi_base(const char *str, int str_base)
{
	int	sign;
	int	result;
	int	val;

	sign = 1;
	result = 0;
	while (*str == ' ' || *str >= 9 && *str <= 13)
		str++;
	if (*str == '-')
	{
		sign = -sign;
		str++;
	}
	else if (*str == '+')
		str++;
	val = get_value(*str);
	while (val != -1 && *str)
	{
		if (val >= str_base)
			break ;
		result = (result * str_base) + val;
		str++;
		val = get_value(*str);
	}
	return (result * sign);
}

int	main(void)
{
	int	n;

	n = 0;
	printf("2a, 16 => %d\n", ft_atoi_base("2a", 16));
	printf("101010, 2 => %d\n", ft_atoi_base("101010", 2));
	printf("-7f, 16 => %d\n", ft_atoi_base("-7f", 16));
	printf("7, 4 => %d\n", ft_atoi_base("7", 4));
	printf("+7, 10 => %d\n", ft_atoi_base("+7", 10));
	printf("  101010, 2 => %d\n", ft_atoi_base("  101010", 2));
	printf("2k, 16 => %d\n", ft_atoi_base("2k", 16));


	return (0);
}
