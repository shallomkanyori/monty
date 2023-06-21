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

**Task 1: pint.**
Implement the `pint` opcode.
**The pint opcode**
The opcode `pint` prints the value at the top of the stack, followed by a new line.
- Usage: `pint`
- If the stack is empty, print the error message `L<line_number>: can't pint, stack empty`, followed by a new line, and exit with the status `EXIT_FAILURE`

**Task 2: pop.**
Implement the `pop` opcode
**The pop opcode**
The opcode `pop` removes the top element of the stack.
- Usage: `pop`
- If the stack is empty, print the error message `L<line_number>: can't pop an empty stack`, followed by a new line, and exit with the status `EXIT_FAILURE`

**Task 3: swap.**
Implement the `swap` opcode.
**The swap opcode**
The opcode `swap` swaps the top two elements of the stack.
- Usage: `swap`
- If the stack contains less than two elements, print the error message `L<line_number>: can't swap, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`
