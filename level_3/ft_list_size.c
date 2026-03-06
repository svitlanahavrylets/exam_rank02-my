// Assignment name  : ft_list_size
// Expected files   : ft_list_size.c, ft_list.h
// Allowed functions:
// --------------------------------------------------------------------------------

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
// }                 t_list;

#include "ft_list_size.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_list_size (t_list *begin_list)
{
	int	count;

	count = 0;
	while (begin_list != NULL)
	{
		count++;
		begin_list = begin_list->next;
	}
	return(count);
}

int	main(void)
{
	t_list *node1 = malloc(sizeof(t_list));
	t_list *node2 = malloc(sizeof (t_list));
	t_list *node3 = malloc(sizeof(t_list));

	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	printf("Size: %d\n", ft_list_size(node1));
	return (0);
}
