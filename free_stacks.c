#include "monty.h"

/**
 * free_stack - Frees a linked list stack.
 * @head: Double pointer to the head of the stack.
 */
void free_stack(stack_t *head)
{
    stack_t *temp;

    while (head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

