#include "monty.h"
/**
 * st_add - program adds top elements of stack
 * @head: head of stack
 * @counter: line number
 * Return: void
 */
void st_add(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, sum;

	h = *head;
	while (h)
	{
	h = h->next;
	len++;
	}

	if (len < 2)
	{
	fprintf(stderr, "L%u: can't add, stack too short\n", counter);
	fclose(bus.file);
	free(bus.content);
	free_stack(*head);
	exit(EXIT_FAILURE);
	}

	h = *head;
	sum = h->n + h->next->n;
	h->next->n = sum;
	*head = h->next;
	free(h);
}
