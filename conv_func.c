#include "monty.h"
/*
 * convert_stack - converts Data structure to stack
 * @stack: stack pointer
 * @line_number: number of line
 */
void convert_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	STACK.is_queue = 0;
}

/*
 * convert_queue - converts Data structure to stack
 * @stack: stack pointer
 * @line_number: number of line
 */
void convert_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	STACK.is_queue = 1;
}
