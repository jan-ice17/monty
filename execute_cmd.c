#include "monty.h"

/**
 * execute - Executes Monty bytecode instructions.
 * @stack: Pointer to the head of the stack.
 * @counter: Line number in the Monty file.
 *
 * Description: This function executes Monty bytecode instructions.
 * Return: No return value (void).
 */
void execute(stack_t **stack, unsigned int counter)
{
    stack_t *h;
    int len = 0, aux;

    h = *stack;
    while (h)
    {
        h = h->next;
        len++;
    }

    if (len < 2)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    h = *stack;
    if (h->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    aux = h->next->n / h->n;
    h->next->n = aux;
    *stack = h->next;
    free(h);
}

