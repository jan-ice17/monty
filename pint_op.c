#include "monty.h"

/**
 * jan_pint - Prints the value at the top of the stack.
 * @head: Double pointer to the head of the stack.
 * @counter: Line number in the Monty file where the pint operation is called.
 */
void jan_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

