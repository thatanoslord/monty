#include "monty.h"
/*
 * rotl - makes top element the last one, and the second top element
 *  of the stack becomes the first one
 * @stack: stack pointer
 * @line_number: number of line
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = STACK.top, *new_top;
	(void)stack;
	(void)line_number;

	if (!STACK.top || !STACK.top->next)
		return;

	while (curr->next)
	curr = curr->next;

	new_top = STACK.top->next;
	curr->next = STACK.top;
	STACK.top->next = NULL;
	STACK.top->prev = curr;
	new_top->prev = NULL;

	STACK.top = new_top;
}

/*
 * rotr - makes top element the last one, and the second top element
 *  of the stack becomes the first one
 * @stack: stack pointer
 * @line_number: number of line
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last = STACK.top;
	(void)stack;
	(void)line_number;

	if (!STACK.top || !STACK.top->next)
		return;

	while (last->next) {
		last = last->next;
	}
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = STACK.top;
		STACK.top->prev = last;

		STACK.top = last;
}
