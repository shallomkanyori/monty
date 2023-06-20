## Project: C - Stacks, Queues - LIFO, FIFO

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

**Task 0: push, pall.**
Implement the `push` and `pall` opcodes.
**The push opcode**
The opcode `push` pushes an element to the stack.
- Usage: `push <int>`
 - where `<int>` is an integer
- if `<int>` is not an integer or if there is no argument given to `push`, print the error message `L<line_number>: usage: push integer`, followed by a new line, and exit with the status `EXIT_FAILURE`
	- where `line_number` is the line number in the file
- You won’t have to deal with overflows. Use the `atoi` function
**The pall opcode**
The opcode `pall` prints all the values on the stack, starting from the top of the stack.
- Usage `pall`
- Format: Each number on its own line
- If the stack is empty, don’t print anything
