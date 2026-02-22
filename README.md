# push_swap

## Description
`push_swap` is a sorting project based on two stacks (`A` and `B`) and a limited set of stack operations (`sa`, `pb`, `ra`, `rra`, etc.).

The goal is to sort a list of integers in ascending order using as few instructions as possible, while respecting strict operation rules.

This repository contains:
- `push_swap` (mandatory): prints the sequence of operations splited by new line to sort the input numbers.
- `checker` (bonus): reads operations from standard input and checks whether they correctly sort the stack.

The program, ***push_swap*** :
- validates and parses input,
- builds linked-list stacks for the input numbers,
- applies small hardcoded sorts for tiny inputs,
- uses a cost-based strategy for larger inputs,
- outputs only valid push_swap instructions.

The program, ***checker*** :
- validates and parses input,
- builds linked-list stacks for the input numbers,
- builds linked-list stacks for the operations,
- 
- outputs only **OK** when success and **KO** when fails.

## Instructions
### 1. Compilation
Build mandatory program:
```bash
make
```

Rebuild from scratch:
```bash
make re
```

Build bonus checker:
```bash
make bonus
```

Clean objects:
```bash
make clean
```
Clean programs:
```bash
make fclean
```

### 2. Execution
#### 2.1 PUSH_SWAP

Run `push_swap` with numbers as separate arguments:
```bash
./push_swap 3 2 5 1 4
```

Run with quoted input:
```bash
./push_swap "3 2 5 1 4"
```
If you want to count the operations do :
```bash
./push_swap "3 2 5 1 4" | wc -l
```
#### 2.2 CHECKER
Run `checker` with numbers as separate arguments:
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```


### 3. Validation with checker_linux
Using local `checker_linux` of 42 school :
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```
Expected output: `OK` when operations are valid and sorting is correct.


### 4. Error behavior
Invalid input (duplicates, overflow, non-numeric tokens, empty arguments) must print:
```text
Error
```
to standard error.

## Resources
### Classic references

- Big-O cheat sheet (simple explanations):
  - https://www.bigocheatsheet.com/

- Visual Big-O intuition:
  - https://visualgo.net/en

- Visualizer
  - https://push-swap42-visualizer.vercel.app/
### How AI was used
AI assistance was used for:
- code review and bug detection,
- explanations of different algorithms,
- README designing.

AI was **not** used to generate code for the project.