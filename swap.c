#include "monty.h"
/**
 * st_swap - program swaps top two elements of stack
 * @head: head of stack
 * @counter: line number
 * Return: void
 */
void st_swap(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, temp;

	h = *head;
	while (h)
	{
	h = h->next;
	len++;
	}

	if (len < 2)
	{
	fprintf(stderr, "L%u: can't swap, stack too short\n", counter);
	fclose(bus.file);
	free(bus.content);
	free_stack(*head);
	exit(EXIT_FAILURE);
	}

	h = *head;
	temp = h->n;
	h->n = h->next->n;
	h->next->n = temp;
}
