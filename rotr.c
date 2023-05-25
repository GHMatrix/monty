#include "monty.h"
/**
 * st_rotr - program rotates the stack to the bottom
 * @head: head of stack
 * @counter: line_number
 * Return: void
 */
void st_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *last = *head;
	stack_t *new_last = NULL;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	while (last->next != NULL)
	{
		last = last->next;
	}

	new_last = last->prev;
	new_last->next = NULL;
	last->prev = NULL;
	last->next = *head;
	(*head)->prev = last;
	*head = last;
}
