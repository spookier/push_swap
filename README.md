# push_swap

push_swap is an algorithmic project developed as part of the curriculum at École 42  

The task involves sorting a stack of integers with a minimal number of specific operations.

The goal of the project is to sort a stack of integers using the least possible number of operations, with a set of allowed operations provided in the .pdf

## Algorithm and Data Structure

The data structure used in this project is a circular linked list, which allows for efficient rotations and swaps  

The algorithm works as follows:

1. The `sort` function checks the size of the stack. If it's 2, it simply swaps the elements in the correct order if needed. If it's larger, it calls `sort_b` and `sort_a` to sort the stacks.
   
2. First, we call `sort_b`. This function pushes the smallest elements from stack A to stack B until only 3 elements remain in stack A. These 3 elements are then sorted with sort_only_3.
   
3. `sort_a` then handles the elements in stack B, determining the optimal place for each element in stack A and performing the necessary rotations and pushes
   
4. Then we will execute the `apply_*` functions (like `apply_rarb`, `apply_rrarrb`, etc.) that are used to perform the optimal sequence of operations determined by `sort_a`

## Usage

Run with `make all` then pass a list of integers as arguments. The program will output a list of operations that will sort the integers  

Example:
```bash
./push_swap 3 2 1
```

>INSERT FIGMA GIF HERE
