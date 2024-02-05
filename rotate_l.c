#include "monty.h"

/**
 * jan_rotl - Rotates the stack to the top.
 * @head: Double pointer to the head of the stack.
 *
 * Description: This function rotates the stack to the top by moving the
 * second element to the top, and updating the pointers accordingly.
 */
void jan_rotl(stack_t **head)
{
	stack_t *tmp = *head, *aux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}

