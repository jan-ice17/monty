#include "monty.h"

/**
 * jan_queue - Adds a new node with the given value to the end of the stack.
 * @head: Double pointer to the head of the stack.
 * @n: Integer value to be added to the new node.
 */
void jan_queue(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (aux)
		aux->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

