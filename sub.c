#include "monty.h"
/**
 * st_sub - program does subtraction top element
 * @head: head of stack
 * @counter: line_number
 * Return: void
 */
void st_sub(stack_t **head, unsigned int counter)
{
	stack_t *current = *head;
	int difference, nodeCount = 0;

	while (current != NULL)
	{
		nodeCount++;
		current = current->next;
	}

	if (nodeCount < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	current = *head;
	difference = current->next->n - current->n;
	current->next->n = difference;
	*head = current->next;
	free(current);
}
