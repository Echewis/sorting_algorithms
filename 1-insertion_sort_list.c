#include "sort.h"
/**
 * swap_the_node - This will swap the node in a listint_t
 * @h: This is the header to the doubly_linked list
 * @n1: This is the pointer to the first node to swap
 * @n2: This is the second node to be swaped
 */

void swap_the_node(listint_t **h, listint_t **n1, listint_t *n2)
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
 * insertion_sort_list - This will sort the doubly linked list of integer
 * @list: This is the pointer to the head of a doubly linked list of integer
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *it, *insertion, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (it = (*list)->next; it != NULL; it = tmp)
	{
		tmp = it->next;
		insertion = it->prev;
		while (insertion != NULL && it->n < insertion->n)
		{
			swap_the_node(list, &insertion, it);
			print_list((const listint_t *)*list);
		}
	}
}
