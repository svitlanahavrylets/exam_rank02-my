#include <stdio.h>
#include <unistd.h>

#define BINARY "01"
#define XYZ "XYZ"
#define OCTAL "01234567"

void	print_binary(int n)
{
	if (n >= 2)
	{
		printf("Йдемо глибше, n було %d\n", n);
		print_binary(n / 2);
		printf("Повернулися з глибини, n зараз %d\n", n);
	}
	write(1, &BINARY[n % 2], 1);

}

void	print_custom(int n)
{
	if (n >= 3)
	{
		print_custom (n / 3);
	}
	write(1, &XYZ[n % 3], 1);
}

void	print_octal(int n)
{
	if (n >= 8)
	{
		print_octal(n / 8);
	}
	write(1, &OCTAL[n % 8], 1);
}

int	main(void)
{
	print_binary(10);
	write(1, "\n", 1);
	print_custom(0);
	write(1, "\n", 1);
	print_octal(13);
	write(1, "\n", 1);
	// printf("print_binary =>%d\n", print_binary(5));
	return(0);
}


