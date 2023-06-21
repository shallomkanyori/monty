#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: a pointer to a pointer to the top of the stack
 * @line_number: the line number of the current instruction in the
 * ByteCodes file
 *
 * Return: nothing.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	int a, b;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		my_exit(1);
	}

	top = *stack;
	a = top->n;
	b = top->next->n;

	top->next->n = b + a;

	pop(stack, line_number);
}