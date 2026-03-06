/*

Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>

*/
#include <unistd.h>

int	get_count(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 1);
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 1);
	return (1);
}

int	main(int ac, char **av)
{
	int	i;
	int	count;

	if (ac == 2)
	{
		i = 0;
		count = 0;
		while (av[1][i])
		{
			count = get_count(av[1][i]);
			while (count > 0)
			{
				write(1, &av[1][i], 1);
				count--;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
