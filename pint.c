#include "monty.h"
/**
 * st_pint - program prints top
 * @head: head of stack
 * @counter: number of line
 * Return: void
 */
void st_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
	fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
	fclose(bus.file);
	free(bus.content);
	free_stack(*head);
	exit(EXIT_FAILURE);
	}

	stack_t *top = *head;

	printf("%d\n", top->n);
}
