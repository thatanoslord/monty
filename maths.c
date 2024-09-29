#include "monty.h"
/*
 * add - adds top 2 elements of a stack
 * @stack: stack pointer
 * @line_number: number of line
 */
void add(stack_t **stack, unsigned int line_number)
{
	int res;
	stack_t *top, *below_top;

	if (!*stack || !(*stack)->next)
	{
		dprintf(2, "L%d: can't add, stack too short\n", line_number);
		fclose(STACK.stream);
		free(STACK.buff);
		free_dbl_list(STACK.top);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	below_top = (*stack)->next;
	res = top->n + below_top->n;
	below_top->n = res;
	free(top);
	below_top->prev = NULL;
	STACK.top = below_top;
}

/*
 * sub - subs top 2 elements of a stack
 * @stack: stack pointer
 * @line_number: number of line
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int res;
	stack_t *top, *below_top;

	if (!*stack || !(*stack)->next)
	{
		dprintf(2, "L%d: can't sub, stack too short\n", line_number);
		fclose(STACK.stream);
		free(STACK.buff);
		free_dbl_list(STACK.top);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	below_top = (*stack)->next;
	res = below_top->n - top->n;
	below_top->n = res;
	free(top);
	below_top->prev = NULL;
	STACK.top = below_top;
}

/*
 * divide - divides top 2 elements of a stack
 * @stack: stack pointer
 * @line_number: number of line
 */
void divide(stack_t **stack, unsigned int line_number)
{
	int res;
	stack_t *top, *below_top;

	if (!*stack || !(*stack)->next)
	{
		dprintf(2, "L%d: can't div, stack too short\n", line_number);
		fclose(STACK.stream);
		free(STACK.buff);
		free_dbl_list(STACK.top);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	below_top = (*stack)->next;
	if (top->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		fclose(STACK.stream);
		free(STACK.buff);
		free_dbl_list(STACK.top);
		exit(EXIT_FAILURE);
	}
	res = below_top->n / top->n;
	below_top->n = res;
	free(top);
	below_top->prev = NULL;
	STACK.top = below_top;
}

/*
 * mul - multiply top 2 elements of a stack
 * @stack: stack pointer
 * @line_number: number of line
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int res;
	stack_t *top, *below_top;

	if (!*stack || !(*stack)->next)
	{
		dprintf(2, "L%d: can't mul, stack too short\n", line_number);
		fclose(STACK.stream);
		free(STACK.buff);
		free_dbl_list(STACK.top);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	below_top = (*stack)->next;
	res = top->n * below_top->n;
	below_top->n = res;
	free(top);
	below_top->prev = NULL;
	STACK.top = below_top;
}

/*
 * mod - modulus top 2 elements of a stack
 * @stack: stack pointer
 * @line_number: number of line
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int res;
	stack_t *top, *below_top;

	if (!*stack || !(*stack)->next)
	{
		dprintf(2, "L%d: can't mod, stack too short\n", line_number);
		fclose(STACK.stream);
		free(STACK.buff);
		free_dbl_list(STACK.top);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	below_top = (*stack)->next;
	if (top->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		fclose(STACK.stream);
		free(STACK.buff);
		free_dbl_list(STACK.top);
		exit(EXIT_FAILURE);
	}
	res = below_top->n % top->n;
	below_top->n = res;
	free(top);
	below_top->prev = NULL;
	STACK.top = below_top;
}
