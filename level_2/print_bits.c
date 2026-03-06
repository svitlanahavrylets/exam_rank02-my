// Assignment name  : print_bits
// Expected files   : print_bits.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
// AT THE END.

// Your function must be declared as follows:

// void	print_bits(unsigned char octet);

// Example, if you pass 2 to print_bits, it will print "00000010"

// #include <stdio.h>
// #include <unistd.h>

// void	print_bits(unsigned char octet)
// {
// 	int				i;
// 	unsigned char	bit;

// 	i = 8;
// 	bit = 0;
// 	while (i--)
// 	{
// 		bit = (octet >> i & 1) + 48;
// 		write (1, &bit, 1);
// 	}
// }

// int	main(void)
// {
// 	unsigned char octet = 2;
// 	print_bits(octet);
// 	return(1);
// }











/*

Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.

Your function must be declared as follows:

void	print_bits(unsigned char octet);

Example, if you pass 2 to print_bits, it will print "00000010"

*/
#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int		maxbit;
	char	bit;

	maxbit = 7;
	while (maxbit >= 0)
	{
		bit = (octet >> maxbit & 1) + '0';
		write(1, &bit, 1);
		maxbit--;
	}
}

int	main(void)
{
	unsigned char	octet;

	octet = 2;
	print_bits(octet);
	return (0);
}
