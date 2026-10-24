#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - deletes a node in a doubly linked list
 * at a given index
 *
 * @head: double pointer to the head of the list
 * @index: index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *saved_head;

	if (head == NULL || *head == NULL)
		return (-1);

	saved_head = *head;
	
	/* Traverse to the node at the specified index */
	while (index != 0)
	{
		if (saved_head == NULL)
			return (-1);
		saved_head = saved_head->next;
		index--;
	}

	/* If index is out of bounds */
	if (saved_head == NULL)
		return (-1);

	/* If we are deleting the head node */
	if (saved_head == *head)
	{
		*head = saved_head->next;
		if (*head != NULL)
			(*head)->prev = NULL;
	}
	else
	{
		/* Update the next pointer of the previous node */
		saved_head->prev->next = saved_head->next;
		
		/* Update the prev pointer of the next node (before freeing!) */
		if (saved_head->next != NULL)
			saved_head->next->prev = saved_head->prev;
	}

	/* Safely free the node at the very end */
	free(saved_head);
	return (1);
}
