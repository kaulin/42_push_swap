# push_swap
A project about sorting integer data using a predefined set of moves.

## General
This was a 42 cursus project focusing on algorithms and data structures. The aim was to sort a set of unique integers using "stacks" A and B, and as few of the following moves as possible:
- swap A (sa), swap B (sb), swap both (ss)
- push A (pa), push B (pa)
- rotate A (ra), rotate B (rb), rotate both (rr)
- reverse rotate A (ra), reverse rotate B (rb), reverse rotate both (rrr)

>[!NOTE]
> The course subject refers to the used data structures as stacks, although the moves allowed are more akin to list operations. My implementation uses a double linked list. For clarity's sake, however, these will be referred to as "stacks" in this README.


## Solution
1. Sort most stack A elements into stack B in descending order, always pushing the element of stack A that requires the least amount of moves to push to the correct position in stack B.
2. Sort remaining stack A elements in ascending order.
3. Push elements from stack B back into stack A, reverse rotating if necessary.
4. Rotate or reverse rotate stack A so that it starts with the smalles integer.

## Optimisations
- Special cases for stacks of sizes 2-5.
- Noticing opportunities to utilise double rotate and double reverse rotate.
- For larger sets, increase the amount of elements left in stack A.

## Possible improvements
- 