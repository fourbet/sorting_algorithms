#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Cocktail Sort algorithm
 *
 * @list: doubly linked list
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tmp;
	listint_t *tmp2;
	listint_t *current;
	listint_t *next;
	listint_t *prev;
	int swapped = 0, count = 0;

	if (list == NULL)
		return;
	current = *list;
	next = current->next;
	if (next == NULL)
		return;
	while (current)
	{
		if (swapped == 0)
		{
			next = current->next;
			if (current->n > next->n)
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
				if (tmp != NULL)
					current = next->prev;
				else
					current = *list;
				print_list(*list);
				count++;
			}
			current = current->next;
			if (current->next == NULL && count == 0)
				return;
			if (current->next == NULL)
			{
				swapped = 1;
				count = 0;
			}
		}
		if (swapped == 1)
		{
			prev = current->prev;
			if (current->n < prev->n)
			{
				tmp = prev->prev;
				prev->prev = current;
				tmp2 = current->next;
				prev->next = tmp2;
				current->next = prev;
				current->prev = tmp;
				if (tmp != NULL)
					tmp->next = current;
				else
				{
					current->prev = NULL;
					*list = current;
				}
				if (tmp2 != NULL)
					tmp2->prev = prev;
				else
					prev->next = NULL;
				print_list(*list);
				if (tmp != NULL)
					current = prev->next;
				else
					current = *list;
				count++;
			}
			current = current->prev;
			if (current == NULL && count == 0)
				return;
			if (current == NULL || current->prev == NULL)
			{
				swapped = 0;
				count = 0;
				current = *list;
			}
		}
	}
}
