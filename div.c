#include "monty.h"
/**
 * st_div - program divides top two elements in stack
 * @head: head of stack
 * @counter: line_number
 * Return: void
 */
void st_div(stack_t **head, unsigned int counter)
{
	stack_t *current = *head;
	int length = 0;
	int division_result;

	while (current)
	{
		current = current->next;
		length++;
	}

	if (length < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	current = *head;

	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	division_result = current->next->n / current->n;
	current->next->n = division_result;
	*head = current->next;
	free(current);
}
