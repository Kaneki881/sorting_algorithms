#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
	if (!list)
	{
		printf("The list is empty.\n");
		return;
	}

	while (list)
	{
		printf("%d", list->n);

		if (list->next)
			printf(", ");
		else
			printf("\n");

		list = list->next;
	}
}
