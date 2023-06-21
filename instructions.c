#include "monty.h"

/**
 * push - pushes an element onto the stack
 * @stack: a pointer to a pointer to the top of the stack
 * @line_number: the line number of the current instruction in the
 * ByteCodes file
 *
 * Return: nothing.
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg, *instruction_cpy = info.instruction;
	int i, n;
	stack_t *new;

	/* get the next argument after the opcode in instruction */
	for (i = 0; instruction_cpy[i]; i++)
		;

	instruction_cpy = &instruction_cpy[++i];
	arg = strtok(instruction_cpy, " \t\n");

	if (arg == NULL || !is_only_digits(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		my_exit(1);
	}

	n = atoi(arg);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		my_exit(1);
	}

	new->n = n;
	new->prev = NULL;
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new;

	*stack = new;
}

/**
 * pall - prints all the values in the stack from the top
 * @stack: a pointer to a pointer to the top of the stack
 * @line_number: the line_number of the current instruction in the
 * ByteCodes file
 *
 * Return: nothing.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;

	(void) line_number;

	if (stack == NULL)
		return;

	curr = *stack;
	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}

/**
 * pint - prints the top value in the stack
 * @stack: stack pointer at the top
 * @line_number: the line_number
 *
 * Return: nothing.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	
	(void) line_number;

	if (*stack == NULL)
		return;

	top = *stack;
	while (top)
	{
		printf("%d\n", top->n);
	}
	else
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		exit (EXIT_FAILURE);
	}

}
