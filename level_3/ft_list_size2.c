// Write a function that returns the number of elements in the linked list that's
// passed to it.

// It must be declared as follows:

// int	ft_list_size(t_list *begin_list);

// You must use the following structure, and turn it in as a file called
// ft_list.h:

// typedef struct    s_list
// {
//     struct s_list *next;
//     void          *data;
// }

#include "ft_list2.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_list_size(t_list *begin_list)
{
    int count;

    count = 0;
    while(begin_list != NULL)
    {
        count++;
        begin_list = begin_list->next; 
    }
    return (count);
}

int main(void)
{
    t_list *n1 = malloc(sizeof(t_list));
    t_list *n2 = malloc(sizeof(t_list));
    t_list *n3 = malloc(sizeof(t_list));

    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;

   printf("result: %d\n", ft_list_size(n1));
    return (0);
}