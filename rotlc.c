#include "monty.h"
/**
 * st_rotl - program rotates stack to top
 * @head: head of stack
 * @counter: line_number
 * Return: void
 */
void st_rotl(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *current = *head;
	stack_t *new_head = NULL;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	new_head = current->next;
	new_head->prev = NULL;

	while (current->next != NULL)
	{
		current = current->next;
	}

	current->next = *head;
	(*head)->next = NULL;
	(*head)->prev = current;
	*head = new_head;
}
