#include "monty.h"
/*
 * tokenize - turns the buffer into an array of strings
 * @buff: line buffer
 * @command: Array of strings to store tokens in
 */

void tokenize(char *buff, char **command)
{
	char *token, *str = buff;
	int i = 0;

	for (; i < 2; str = NULL, i++)
	{
		token = strtok(str, " \t\n");
		if (!token || token[0] == '#')
			return;
		command[i] = token;
	}
}

/*
 * is_digit - checks if a string consists of digits only
 * @str: string to check
 * Return: 1 if it's all digits, 0 otherwise
 */

int is_digit(char *str)
{
	int i = 0;

	if (str[0] == '-')
	i++;

	for (; str[i]; i++)
	{
		if (isdigit(str[i]) == 0)
		return (0);
	}
	return (1);
}

/*
 * reset_command - resets command values to NULL
 * @command: command
 */
void reset_command(char **command)
{
	int i;

	for (i = 0; i < 2; i++)
	command[i] = NULL;
}

/*
 * pchar - prints the character at the top of the stack
 * @stack: stack pointer
 * @line_number: number of line
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	int ch;

	if (!*stack)
	{
		dprintf(2, "L%d: can't pchar, stack empty\n", line_number);
		fclose(STACK.stream);
		free(STACK.buff);
		free_dbl_list(STACK.top);
		exit(EXIT_FAILURE);
	}

	ch = (*stack)->n;

	if (ch < 0 || ch > 127)
	{
		dprintf(2, "L%d: can't pchar, value out of range\n", line_number);
		fclose(STACK.stream);
		free(STACK.buff);
		free_dbl_list(STACK.top);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", ch);
}

/*
 * pstr - prints a string starting from top of the stack
 * @stack: stack pointer
 * @line_number: number of line
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	int ch;
	stack_t *curr = *stack;

	(void)line_number;
	if (!*stack)
	{
		printf("\n");
		return;
	}

	while (curr)
	{
		ch = curr->n;
		if (ch < 0 || ch > 127 || ch == 0)
			break;
		printf("%c", ch);
		curr = curr->next;
	}

	printf("\n");
}
