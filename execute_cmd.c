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
    stack_t *h, *temp;
    int len = 0, result;

    h = *stack;
    
    /* Check if stack is empty */
    if (h == NULL)
    {
        fprintf(stderr, "L%d: stack is empty\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    /* Check if stack has at least 2 elements */
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

    /* Check for division by zero */
    h = *stack;
    if (h->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    /* Perform division and update stack */
    temp = h->next;
    result = temp->n / h->n;
    temp->n = result;
    *stack = temp;
    free(h);
}

