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
