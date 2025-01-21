
 **Push_swap** is an algorithm challenge that requires sorting a stack of integers using a minimal set of operations.
The goal is to create a program which outputs the most efficient sequence of instructions to sort the integers in ascending order.


## Rules and Operations

### Stacks

- **Stack A**: Initially contains the unsorted integers provided as input.
- **Stack B**: Starts empty and is used as a helper stack.
- **Goal**: Sort all integers in ascending order in **Stack A**.

### Available Operations

1. **Swap**:
   - `sa`: Swap the first two elements of Stack A.
   - `sb`: Swap the first two elements of Stack B.
   - `ss`: Perform both `sa` and `sb` simultaneously.

2. **Push**:
   - `pa`: Move the top element of Stack B to Stack A.
   - `pb`: Move the top element of Stack A to Stack B.

3. **Rotate**:
   - `ra`: Shift all elements of Stack A up by one. The first element becomes the last.
   - `rb`: Shift all elements of Stack B up by one. The first element becomes the last.
   - `rr`: Perform both `ra` and `rb` simultaneously.

4. **Reverse Rotate**:
   - `rra`: Shift all elements of Stack A down by one. The last element becomes the first.
   - `rrb`: Shift all elements of Stack B down by one. The last element becomes the first.
   - `rrr`: Perform both `rra` and `rrb` simultaneously.



The program takes a list of integers as input, representing stack A, and outputs the smallest sequence of operations required to sort stack A in ascending order. The first number corresponds to the top of Stack A.

The program displays `Error` if:
  - inputs are not integers
  - inputs are duplicates or exceed integer limits

Example:
```bash
./push_swap 3 14 7 155 0

