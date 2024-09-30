#include "monty.h"
/*
 * run_command - runs selected command
 * @line: line number
 */

void run_command(int line)
{
	char *command = STACK.command[0];
	void (*operation)(stack_t **stack, unsigned int line_number);

	operation = get_operation(command);
	if (!operation)
	{
		dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line, command);
		free_dbl_list(STACK.top);
		free(STACK.buff);
		fclose(STACK.stream);
		exit(EXIT_FAILURE);
	}

	operation(&STACK.top, line);
}

/*
 * get_operation - returns the operation that should be executed
 * @command: command to find its corresponding operation
 * Return: function pointer operation as per specified function
 */

void (*get_operation(char *command))(stack_t **stack, unsigned int line_number)
{
	instruction_t instr[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	{"add", add},
	{"nop", nop},
	{"sub", sub},
	{"div", divide},
	{"mul", mul},
	{"mod", mod},
	{"pchar", pchar},
	{"pstr", pstr},
	{"rotl", rotl},
	{"rotr", rotr},
	{"stack", convert_stack},
	{"queue", convert_queue},
	{NULL, NULL}};
	int i;

	for (i = 0; instr[i].opcode; i++)
	{
		if (!strcmp(command, instr[i].opcode))
			return (instr[i].f);
	}
	return (NULL);
}

/*
 * pall - prints all elements in the stack
 * @stack: stack pointer
 * @line_number: line number
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = STACK.top;

	(void)stack;
	(void)line_number;

	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}
