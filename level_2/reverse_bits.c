// Assignment name  : reverse_bits
// Expected files   : reverse_bits.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function that takes a byte, reverses it, bit by bit (like the
// example) and returns the result.

// Your function must be declared as follows:

// unsigned char	reverse_bits(unsigned char octet);

// Example:

//   1 byte
// _____________
//  0010  0110
//      ||
//      \/
//  0110  0100

#include <stdio.h>
#include <unistd.h>

// unsigned char	reverse_bits(unsigned char octet)
// {
// 	unsigned int	i;
// 	unsigned char	res;

// 	i = 8;
// 	res = 0;

// 	while (i--)
// 	{
// 		res = (res << 1) | (octet & 1);
// 		octet = (octet >> 1);
// 	}
// 	return (res);
// }

// int	main(void)
// {
// 	unsigned char	bit = 0;
// 	unsigned char	res = reverse_bits((unsigned char)2);
// 	int 			i = 8;

// 	while (i--)
// 	{
// 		bit = (res >> i & 1) + 48;
// 		printf("%c\n", bit);
// 	}
// 	return (1);
// }


unsigned char	reverse_bits(unsigned char octet)
{
	int		maxbit;
	char	res;

	maxbit = 8;
	while (maxbit--)
	{
		res = res << 1 | octet & 1;
		octet = octet >> 1;
	}
	return (res);
}

void	print_bits(unsigned char octet)
{
	int		maxbit;
	char	bit;

	maxbit = 8;
	while (maxbit--)
	{
		bit = (octet >> maxbit & 1) + '0';
		write(1, &bit, 1);
	}

}

int	main(void)
{
	unsigned char	octet;
	unsigned char	result;

	octet = 42;
	printf("origin octet: %u\n", octet);
	print_bits(octet);

	result = reverse_bits(octet);
	printf("result: %u\n", result);
	print_bits(result);
	
	return (0);
}




