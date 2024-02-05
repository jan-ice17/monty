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

    /* Check the number of command-line arguments */
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    /* Open the Monty bytecode file */
    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /* Read each line from the file and execute Monty bytecode instructions */
    while (read_line > 0)
    {
        content = NULL;
        read_line = getline(&content, &size, file);
        counter++;

        if (read_line > 0)
        {
            /* Extract opcode */
            char *opcode = strtok(content, " \n\t\r");

            /* Check the opcode and perform appropriate action */
            if (opcode != NULL && strcmp(opcode, "push") != 0 && strcmp(opcode, "pop") != 0
                && strcmp(opcode, "swap") != 0 && strcmp(opcode, "add") != 0
                && strcmp(opcode, "nop") != 0 && strcmp(opcode, "sub") != 0
                && strcmp(opcode, "div") != 0 && strcmp(opcode, "mul") != 0
                && strcmp(opcode, "mod") != 0 && strcmp(opcode, "pstr") != 0
                && strcmp(opcode, "rotl") != 0 && strcmp(opcode, "rotr") != 0
                && strcmp(opcode, "queue") != 0 && strcmp(opcode, "stack") != 0)
            {
                /* Handle other opcodes accordingly */
                execute(&stack, counter);
            }
        }

        free(content);
    }

    /* Free allocated memory and close the file */
    free_stack(stack);
    fclose(file);
    return (0);
}

