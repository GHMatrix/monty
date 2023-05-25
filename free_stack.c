#include "monty.h"
/**
 * free_stack - program frees doubly linked list
 * @head: head of stack
 */
void free_stack(stack_t *head)
{
	stack_t *current, *next;

	current = head;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
