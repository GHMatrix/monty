#include "monty.h"
#include <stdio.h>

#define MAX_LINE_LENGTH 1000

bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - interpreter
 * @argc: number of arguments
 * @argv: file position or location
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char line[MAX_LINE_LENGTH];
	FILE *file;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	bus.file = file;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
	{
		bus.content = line;
		counter++;

		if (line[0] != '\n' && line[0] != '#')
	{
			size_t len = strlen(line);

			if (len > 0 && line[len - 1] == '\n')
				line[len - 1] = '\0';

			execute(line, &stack, counter, file);
		}
	}

	free_stack(stack);
	fclose(file);
	return (0);
}
