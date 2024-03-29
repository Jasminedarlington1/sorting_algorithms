#include "sort.h"

/**
 * swap_nodes - function that swaps two nodes
 * @node1: Pointer to address of node 1
 * @node2: Pointer to address of node 2
 * @list: blbla
 * Return: Nothing
 */
void swap_nodes(listint_t **list, listint_t **node1, listint_t **node2)
{
	listint_t *tmp = (*node1)->prev;

	(*node1)->next = (*node2)->next;

	if ((*node2)->next != NULL)
		(*node2)->next->prev = *node1;

	(*node1)->prev = *node2;
	(*node2)->next = *node1;
	(*node2)->prev = tmp;

	if ((*node2)->prev != NULL)
		(*node2)->prev->next = *node2;
	else
		*list = *node2;
}

/**
 * insertion_sort_list - function that sorts a doubly linked list
 * using Insertion Sort
 * @list: input
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *a = NULL, *key = NULL;

	if (!list || !(*list))
		return;

	for (a = *list; a != NULL; a = a->next)
	{
		while (a->next != NULL && a->n > a->next->n)
		{
			key = a->next;
			while (key->prev != NULL && key->n < key->prev->n)
			{
				swap_nodes(list, &key->prev, &key);
				print_list(*list);
			}
		}
	}
}
