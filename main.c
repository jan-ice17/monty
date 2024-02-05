#define _GNU_SOURCE
#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - Entry point for the Monty interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 * Return: 0 on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
    char *content;
    FILE *file;
    size_t size = 0;
    ssize_t read_line = 1;
    stack_t *stack = NULL;
    unsigned int counter = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (read_line > 0)
    {
        content = NULL;
        read_line = getline(&content, &size, file);
        counter++;
        if (read_line > 0)
        {
            execute(&stack, counter);
        }
        free(content);
    }

    free_stack(stack);
    fclose(file);
    return (0);
}

