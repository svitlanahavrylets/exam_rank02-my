/*

Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>

*/

#include <unistd.h>

int is_space(char c) {
    return (c == ' ' || c == '\t');
}

int main(int ac, char **av) {
    if (ac > 1) {
        int i = 0;
        int start;
        int end;

        while (av[1][i] && is_space(av[1][i]))
            i++;
        start = i;
        while (av[1][i] && !is_space(av[1][i]))
            i++;
        end = i;
        while (av[1][i] && is_space(av[1][i]))
            i++;
        int has_other_words = 0;
        while (av[1][i]) {
            if (!is_space(av[1][i])) {
                if (has_other_words)
                    write(1, " ", 1);
                while (av[1][i] && !is_space(av[1][i])) {
                    write(1, &av[1][i], 1);
                    i++;
                    has_other_words = 1;
                }
            } else {
                i++;
            }
        }
        if (has_other_words)
            write(1, " ", 1);
        while (start < end) {
            write(1, &av[1][start], 1);
            start++;
        }
    }
    write(1, "\n", 1);
    return (0);
}