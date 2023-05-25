#include "monty.h"
/**
 * st_pint - program prints top
 * @head: head of stack
 * @counter: number of line
 * Return: void
 */
#include "monty.h"

void st_pint(stack_t **head, unsigned int counter)
{
	stack_t *top;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	top = *head;
	printf("%d\n", top->n);
}
