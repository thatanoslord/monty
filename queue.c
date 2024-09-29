#include "monty.h"
/*
 * queue_push - push an element to the end of the queue
 * @line_number: number of line
 */
void queue_push(int line_number)
{
	int n;
	char **command = STACK.command;
	stack_t *new, *last;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_stack_data();
		exit(EXIT_FAILURE);
	}

	if (command[1] && is_digit(command[1]))
	n = atoi(command[1]);
	else
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		free_stack_data();
		free(new);
		exit(EXIT_FAILURE);
	}

	new->n = n;
	if (!STACK.top)
	{
		new->next = NULL;
		new->prev = NULL;
		STACK.top = new;
		return;
	}
	last = STACK.top;
	while (last->next)
	last = last->next;
	new->prev = last;
	new->next = NULL;
	last->next = new;
}
