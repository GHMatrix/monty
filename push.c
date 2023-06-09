#include "monty.h"
/**
 * st_push - adds node to stack
 * @head: head of stack
 * @counter: number line
 * Return: void
 */
void st_push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (bus.arg)
	{
	if (bus.arg[0] == '-')
		j++;
	while (bus.arg[j] != '\0')
	{
		if (bus.arg[j] > '9' || bus.arg[j] < '0')
		flag = 1;
		j++;
	}
	if (flag == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(bus.arg);
	if (bus.lifi == 0)
	addnode(head, n);
	else
	addqueue(head, n);
}
