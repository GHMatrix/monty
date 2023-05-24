#include "monty.h"
/**
 * st_pop - program removes top element of stack
 * @head: head of stack
 * @counter: number line
 * Return: void
 */
void st_pop(stack_t **head, unsigned int counter)
{
	stack_t *top;

	if (*head == NULL)
	{
	fprintf(stderr, "L%u: can't pop an empty stack\n", counter);
	fclose(bus.file);
	free(bus.content);
	free_stack(*head);
	exit(EXIT_FAILURE);
	}

	top = *head;
	*head = top->next;
	free(top);
}
