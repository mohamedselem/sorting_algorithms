#include "sort.h"

/**
 * swap_nodes - func to Swap two nodes in a doubly-linked list.
 * @h:  pointer to the head of doubly-linked list.
 * @n1:  pointer to the first node to swap.
 * @n2: The second node to be swapped.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - func to Sorts a doubly linked list of integers
 *                       using insertion sort algorithm.
 * @list: pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swapping happen.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *itr, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (itr = (*list)->next; itr != NULL; itr = temp)
	{
		temp = itr->next;
		insert = itr->prev;
		while (insert != NULL && itr->n < insert->n)
		{
			swap_nodes(list, &insert, itr);
			print_list((const listint_t *)*list);
		}
	}
}
