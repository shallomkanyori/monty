#include "monty.h"

info_t info = {NULL, NULL, NULL}; /* initialize info global variable */

/**
 * main - interpreter for Monty ByteCodes files
 * @ac: the number of program arguments
 * @av: the program arguments
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int ac, char **av)
{
	char *instruction_cpy = NULL, *opcode;
	unsigned int line_num = 0;
	size_t instruction_len = 0;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	info.file = fopen(av[1], "r");
	if (info.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&info.instruction, &instruction_len, info.file) != -1)
	{
		line_num++;
		instruction_cpy = info.instruction;
		opcode = strtok(instruction_cpy, " \t\n");
		if (opcode == NULL)
			continue;

		handle_instruction(opcode, line_num);
	}

	if (!feof(info.file))
	{
		fprintf(stderr, "Error reading file %s\n", av[1]);
		my_exit(1);
	}

	my_exit(0);
	exit(EXIT_SUCCESS); /* does nothing */
}

/**
 * handle_instruction - handles the execution of the given instruction
 * @opcode: the opcode of the given instruction
 * @line_num: the line number of the instruction in the file
 *
 * Return: nothing.
 */
void handle_instruction(char *opcode, unsigned int line_num)
{
	instruction_t instructions[] = {{"push", push}, {"pall", pall},
					{"pint", pint}, {"pop", pop},
					{"swap", swap}, {"add", add},
					{"nop", nop}, {"add", add},
					{NULL, NULL}};
	int i;

	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			instructions[i].f(&info.stack, line_num);
			return;
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_num, opcode);
	my_exit(1);
}

/**
 * my_exit - exits the program
 * @failure: 1 if failure, 0 if otherwise
 *
 * Return: nothing.
 */
void my_exit(int failure)
{
	free(info.instruction);
	free_stack(info.stack);
	fclose(info.file);

	if (failure)
		exit(EXIT_FAILURE);

	exit(EXIT_SUCCESS);
}
