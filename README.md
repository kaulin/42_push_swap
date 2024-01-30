# push_swap
A project about manipulating and sorting stack data in an optimal way.

## Solution
1. Sort most stack A elements into stack B in descending order, always pushing the element of stack A that requires the least amount of moves to push to the correct position in stack B.
2. Sort remaining stack A elements in ascending order.
3. Push elements from stack B back into stack A, reverse rotating if necessary.
4. Rotate or reverse rotate stack A so that it starts with the smalles integer.

## Optimisations
- Special cases for stacks of sizes 2-5.
- Noticing opportunities to utilise double rotate and double reverse rotate.
- For larger sets, increase the amount of elements left 

