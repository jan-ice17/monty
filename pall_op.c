#include "monty.h"

/**
 * jan_pall - Prints all the elements of the stack.
 * @head: Double pointer to the head of the stack.
 * @counter: Line number in the Monty file where the pall operation is called.
 */
void jan_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

