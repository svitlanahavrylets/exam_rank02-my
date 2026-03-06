/*

Assignment name  : rot_13
Expected files   : rot_13.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the letter 13 spaces ahead in alphabetical order.

'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

The output will be followed by a newline.

If the number of arguments is not 1, the program displays a newline.

Example:

$>./rot_13 "abc"
nop
$>./rot_13 "My horse is Amazing." | cat -e
Zl ubefr vf Nznmvat.$
$>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
NxwuM mYXVWm , 23l $
$>./rot_13 | cat -e
$
$>
$>./rot_13 "" | cat -e
$
$>

*/
#include <unistd.h>
#include <stdio.h>

int	get_new_letter(int c)
{
	if (c >= 'A' && c <= 'M')
		return (c + 13);
	if (c >= 'N' && c <= 'Z')
		return ('M' - ('Z' - c));
	if (c >= 'a' && c <= 'm')
		return (c + 13);
	if (c >= 'n' && c <= 'z')
		return ('m' - ('z' - c));
}
int	main (int ac, char **av)
{
	int	i;
	int	new;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			new = get_new_letter(av[1][i]);
			if (av[1][i] >= 'A' && av[1][i] <= 'Z' ||
			av[1][i] >= 'a' && av[1][i] <= 'z')
			{
				write(1, &new, 1);
			}
			else
				write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

