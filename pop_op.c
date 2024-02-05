#include "monty.h"

/**
 * jan_pop - Removes the top element of the stack.
 * @head: Double pointer to the head of the stack.
 * @counter: Line number in the Monty file where the pop operation is called.
 */
void jan_pop(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}

