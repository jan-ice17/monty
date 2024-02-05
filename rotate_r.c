#include "monty.h"

/**
 * jan_rotr - Rotates the stack to the bottom.
 * @head: Double pointer to the head of the stack.
 *
 * Description: This function rotates the stack to the bottom by moving the
 * last element to the top, and updating the pointers accordingly.
 */
void jan_rotr(stack_t **head)
{
    stack_t *copy;

    copy = *head;
    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }
    while (copy->next)
    {
        copy = copy->next;
    }
    copy->next = *head;
    copy->prev->next = NULL;
    copy->prev = NULL;
    (*head)->prev = copy;
    (*head) = copy;
}

