#include "monty.h"
/**
 * execute - executes opcode
 * @stack: head stack linked list
 * @line_counter: line counter
 * @content: line content
 * @file: pointer to monty file
 * Return: 1
 */
int execute(char *content, stack_t **stack,
		unsigned int line_counter, FILE *file)
{
	instruction_t opcodes[] = {
		{"push", st_push}, {"pall", st_pall}, {"pint", st_pint},
		{"pop", st_pop},
		{"swap", st_swap},
		{"add", st_add},
		{"nop", st_nop},
		{"sub", st_sub},
		{"div", st_div},
		{"mul", st_mul},
		{"mod", st_mod},
		{"pchar", st_pchar},
		{"pstr", st_pstr},
		{"rotl", st_rotl},
		{"rotr", st_rotr},
		{"queue", st_queue},
		{"stack", st_stack},
		{NULL, NULL}
	};

	unsigned int i = 0;
	char *opcode;

	opcode = strtok(content, " \n\t");

	if (opcode && opcode[0] == '#')
		return (0);

	bus.arg = strtok(NULL, " \n\t");

	while (opcodes[i].opcode && opcode)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, line_counter);
			return (0);
		}
		i++;
	}

	if (opcode && opcodes[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_counter, opcode);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	return (1);
}
