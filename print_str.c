#include "monty.h"

/**
 * jan_pstr - Prints the string starting at the top of the stack,
 *             followed by a new line.
 * @head: Double pointer to the head of the stack.
 * @counter: Line number in the Monty file where the pstr operation is called.
 */
void jan_pstr(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}

