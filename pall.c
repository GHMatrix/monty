#include "monty.h"
/**
 * st_pall - program prints stack
 * @head: head of stack
 * @counter: not utilized
 * Return: void
 */
void st_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
	return;

	while (h != NULL)
	{
	printf("%d\n", h->n);
	h = h->next;
	}
}
