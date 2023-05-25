#include "monty.h"
/**
 * st_queue - program prints top
 * @head: head of stack
 * @counter: line_number
 * Return: void
 */
void st_queue(stack_t **head, unsigned int counter)
{
	(void)counter;
	bus.lifi = 1;
	(void)head;
}

/**
 * addqueue - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * Return: no return
*/
void addqueue(stack_t **head, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	stack_t *current = *head;

	if (new_node == NULL)
	{
		printf("Error\n");
		return;
	}

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return;
	}

	while (current->next != NULL)
	{
		current = current->next;
	}

	current->next = new_node;
	new_node->prev = current;
}
