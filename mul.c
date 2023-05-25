#include "monty.h"
/**
 * st_mul - program multiplies top two elements of stack
 * @head: head of stack
 * @counter: line_number
 * Return: void
 */
void st_mul(stack_t **head, unsigned int counter)
{
	stack_t *current;
	int length = 0, result;

	current = *head;

	while (current)
	{
		current = current->next;
		length++;
	}

	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	current = *head;
	result = current->next->n * current->n;
	current->next->n = result;
	*head = current->next;
	free(current);
}
