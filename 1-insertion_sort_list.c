#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 *
 * @list: doubly linked list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp;
	listint_t *tmp2;
	listint_t *current;
	listint_t *next;

	if (list == NULL)
		return;
	current = *list;
	next = current->next;
	while (current && current->next != NULL)
	{
		next = current->next;
		while (current->n > next->n)
		{
			tmp = current->prev;
			current->prev = next;
			tmp2 = next->next;
			current->next = next->next;
			next->next = current;
			next->prev = tmp;
			if (tmp != NULL)
				tmp->next = next;
			else
			{
				next->prev = NULL;
				*list = next;
			}
			if (tmp2 != NULL)
				tmp2->prev = current;
			else
				current->next = NULL;
			print_list(*list);
			if (tmp != NULL)
				current = next->prev;
			else
				current = *list;
		}
		current = current->next;
	}
}
