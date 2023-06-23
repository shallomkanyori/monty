#include "monty.h"

/**
 * mod - computes the remainder of the division of the second top element of
 * the stack by the top element of the stack
 * @stack: a pointer to a pointer to the top of the stack
 * @line_number: the line number of the current instruction in the
 * ByteCodes file
 *
 * Return: nothing.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	int a, b;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		my_exit(1);
	}

	top = *stack;
	a = top->n;
	if (a == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		my_exit(1);
	}

	b = top->next->n;

	top->next->n = b % a;

	pop(stack, line_number);
}

/**
 * pchar - prints the char at the top of the stack if possible
 * @stack: a pointer to a pointer to the top of the stack
 * @line_number: the line number to the current instruction in the
 * ByteCodes file
 *
 * Return: nothing.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int c;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		my_exit(1);
	}

	c = (*stack)->n;
	if (!isascii(c))
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		my_exit(1);
	}

	printf("%c\n", c);
}

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: a pointer to a pointer to the top of the stack
 * @line_number: the line_number of the current instruction in the
 * ByteCode file
 *
 * Return: nothing.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;

	(void) line_number;

	curr = stack ? *stack : NULL;

	while (curr)
	{
		if (!isascii(curr->n) || curr->n == 0)
			break;

		printf("%c", curr->n);
		curr = curr->next;
	}

	printf("\n");
}
