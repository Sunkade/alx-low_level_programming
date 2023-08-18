#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node of a dlistint_t linked list.
 *
 * @head: Pointer to the head of the list.
 * @index: Index of the node to search for, starting from 0.
 * Return: Nth node or NULL.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int size = 0;
	dlistint_t *temp = head;

	while (temp)
	{
	if (index == size)
		return (temp);
	size++;
	temp = temp->next;
	}

	return (NULL);
}
