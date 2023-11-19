#include "sort.h"

/**
 * insertion_sort_list- Sorts a doubly linked list of integers in asc order
 * @list: Pointer to the head of the list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;
	int value;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		value = current->n;
		temp = current->next;
		prev = current->prev;

		while (prev && value < prev->n)
		{
			if (prev->prev)
				prev->prev->next = current;

			current->prev = prev->prev;
			prev->next = current->next;
			prev->prev = current;

			if (current->next)
				current->next->prev = prev;

			current->next = prev;
			prev = current->prev;

			if (!prev)
				*list = current;

			print_list(*list);
		}

		current = temp;
		if (!current)
			break;
		prev = current->prev;
	}
}
