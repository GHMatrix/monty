#include "monty.h"
/**
 * st_mod - computes remainder of division
 * @head: head of stack
 * @counter: line_number
 * Return: void
 */
void st_mod(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, remainder;

	h = *head;
	while (h)
	{
	h = h->next;
	len++;
	}

	if (len < 2)
	{
	fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
	fclose(bus.file);
	free(bus.content);
	free_stack(*head);
	exit(EXIT_FAILURE);
	}

	h = *head;
	if (h->n == 0)
	{
	fprintf(stderr, "L%d: division by zero\n", counter);
	fclose(bus.file);
	free(bus.content);
	free_stack(*head);
	exit(EXIT_FAILURE);
	}

	remainder = h->next->n % h->n;
	h->next->n = remainder;
	*head = h->next;
	free(h);
}
