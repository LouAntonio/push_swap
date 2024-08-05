<a href="#">
    <img src="https://github.com/LouAntonio/42-resources/blob/main/resourses/push_swap.png" style="width: 100%"/>
</a>

# PUSH_SWAP
"Because Swap_push isn’t as natural"

Push_swap is the first really difficult project in the Common Core. The goal is to create a program whitch recieve a list of numbers and sort them using a Sorting Algorithm, and obeying a list of possible moves to sort the list.

It must be the most efficcient as possible, and the final mark deppends of it. The project must be done using the concept of Data Structures, specifically Stacks.

> Stack is a linear data structure that follows the Last In First Out (LIFO) principle

For the Sorting Alg, i used a modified [turkish algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

<a href="#">
    <img src="https://github.com/LouAntonio/42-resources/blob/main/resourses/avaluations/push_swap.png"/>
</a>

I mist 5 points because my program prints an error message when called without parameters, when it should print notting.

### MOVES
It is mandatory to use only the following moves to sort the stack:
- [x] `pa` **(push A)**: Take the first element at the top of B and put it at the top of A. Do nothing if B is empty.
- [x] `pb` **(push B)**: Take the first element at the top of A and put it at the top of B. Do nothing if A is empty.
- [x] `sa` **(swap A)**: Swap the first 2 elements at the top of stack A. Do nothing if there are only one or no elements.
- [x] `sb` **(swap B)**: Swap the first 2 elements at the top of stack B. Do nothing if there are only one or no elements.
- [x] `ss`: `sa` and `sb` at the same time.
- [x] `ra` **(rotate A)**: Shift all elements of stack A up by 1. The first element becomes the last one.
- [x] `rb` **(rotate B)**: Shift all elements of stack B up by 1. The first element becomes the last one.
- [x] `rr` : `ra` and `rb` at the same time.
- [x] `rra` **(reverse rotate A)**: Shift all elements of stack A down by 1. The last element becomes the first one.
- [x] `rrb` **(reverse rotate B)**: Shift all elements of stack b down by 1. The last element becomes the first one.
- [x] `rrr` : `rra` and `rrb` at the same time.


#### GRADE
> The grade depends on how efficient the program's sorting process is.
 
- [x] Sorting **3 values**: no more than **3 actions**.
- [x] Sorting **5 values**: no more than **12 actions**.
- [x] Sorting **100 values**: **rating from 1 to 5 points** depending on the number of actions:

   - [ ] **5 points** for less than **700 actions**.
   - [ ] **4 points** for less than **900 actions**.
   - [x] **3 points** for less than **1100 actions**.
   - [x] **2 points** for less than **1300 actions**.
   - [x] **1 point** for less than **1500 actions**.
- [x] Sorting **500 values**: **rating from 1 to 5 points** depending on the number of actions:

   - [ ] **5 points** for less than **5500 actions**.
   - [x] **4 points** for less than **7000 actions**.
   - [x] **3 points** for less than **8500 actions**.
   - [x] **2 points** for less than **10000 actions**.
   - [x] **1 point** for less than **11500 actions**.
