**Push_swap** is an algorithm challenge that requires sorting a stack of integers using a minimal set of operations.  
The goal is to create a program that outputs the most efficient sequence of instructions to sort the integers in ascending order.

### Core Functionality

- **Efficient Sorting**: Generates a minimal sequence of instructions to sort the input integers.  
- **Error Handling**: Handles invalid input, including:
  - Non-integer values.
  - Duplicates.
  - Values outside the range of a signed integer.


## Rules and Operations

### Stacks

- **Stack A**: Initially contains the unsorted integers provided as input.  
- **Stack B**: Starts empty and is used as a helper stack.  
- **Goal**: Sort all integers in ascending order in **Stack A**.

### Operations

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


### Example Usage

The program takes a list of integers as input, representing **Stack A**, and outputs the smallest sequence of operations required to sort it in ascending order.

Example: ./push_swap 3 14 7 155 0

---
# Bonus: Checker Program

The **Checker** program is a bonus addition to the **Push_swap** project. It allows you to verify whether a series of sorting instructions successfully sorts the stack provided as input.

## How It Works

### Input

1. **Initial Stack**: The program accepts a list of integers as input, representing Stack A.  
2. **Sorting Instructions**: Reads sorting instructions from the standard input, one per line. Instructions must be followed by `\n`.

### Validation

- The program applies the sorting instructions to the provided stacks.
- At the end of the operations:
  - If Stack A is sorted in ascending order and Stack B is empty, the program outputs `OK`.
  - Otherwise, it outputs `KO`.

### Error Handling

The program outputs `Error` if:
- Invalid or incorrectly formatted instructions are provided.
- Input values are not integers or exceed integer limits.
- Duplicate values are detected.

---

The **Checker** program supports all the operations used in **Push_swap**:


## Example Usage

### Valid Case
```bash
$ ./checker 3 2 1 0
rra
pb
sa
rra
pa
OK

