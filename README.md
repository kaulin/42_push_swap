> [!WARNING]
> To anyone in general, but fellow 42 students in particular: when faced with a problem, it is always better to attempt solving it first alone without consulting the previous works of others. Your precursors were no smarter than and just as fallible as you; Blindly following their footsteps will only lead you on the same detours they took and prevent you from seeing new, faster routes along the way.

# push_swap
A project about sorting integer data using a predefined set of moves.

> [!NOTE]  
> 42 Cursus C projects need to follow specific rules and formatting dictated by the [42 Norm](https://github.com/42School/norminette/tree/master/pdf).

## Introduction
This was a 42 cursus project focusing on algorithms and data structures. The aim was to sort a set of unique integers using "stacks" A and B, and as few of the following moves as possible:
- swap A (sa), swap B (sb), swap both (ss)
- push A (pa), push B (pa)
- rotate A (ra), rotate B (rb), rotate both (rr)
- reverse rotate A (ra), reverse rotate B (rb), reverse rotate both (rrr).

>[!NOTE]
> The course subject refers to the used data structures as stacks, although the moves allowed are more akin to list operations. My implementation uses a double linked list. For clarity's sake, however, these will be referred to as stacks in this README.

## Installation
Git clone the repository, move into it and run `make` to compile the program.

## Usage
Run the program with:

`./push_swap "numbers"`

`"numbers"` should be replaced with a set of unique integers between INT_MIN and INT_MAX. The input can be a single string of integers separated by whitespace, multiple strings of single integers or a combination of these. The output for valid input will be the moves required to sort these integers.

## Implementation
A brief description of my approach to the problem, the optimisations I made and possible areas that could be improved.

### Solution
1. Sort stack A elements into stack B in descending order, always pushing the element of stack A that requires the least amount of moves to push to the correct position in stack B. Leave 5-15 elements in stack A to be sorted separately.
2. Sort remaining stack A elements in ascending order.
3. Push elements from stack B back into stack A, reverse rotating if necessary.
4. Rotate or reverse rotate stack A so that it starts with the smallest integer.

### Optimisations
- Checking if the stack is already in ascending order, but doen't necessarily start with the smallest integer (stacks of size 2 always belong to this set).
-  Special, hardcoded, cases for small stack sizes (3-5).
- Noticing opportunities to utilise double rotate and double reverse rotate.
- For larger sets, increase the amount of elements left in stack A to prevent (in the worst case) several counts of n/2 rotates.

### Possible improvements
- Adjust the number of elements to be left in stack A and sorted separately dynamically based on the number of initial stack items. With my current understanding (gained with repeated testing, not through mathematical models), the sweet spot is to leave ~3% of the stack in A.
- Refactoring. The idea to increase the number of elements to be left in stack A came after almost two weeks of struggling to push worst case instances of 500 integers to below 5500 moves. The final implementation, especially functions in the ps_sort.c file, could be written and named more clearly.

## Acknowledgements
- Initial idea for approach: David Horvath
- Great [tester](https://github.com/gemartin99/Push-Swap-Tester) by [Gerard Martinez](https://github.com/gemartin99)
- Peer evaluators: Riku Louhela, [Pablo Markaide](https://github.com/pmarkaide), Dmitrii Shatilov
