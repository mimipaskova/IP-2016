# IP-2016 Week 5 - Loops, Arrays (1-dimensional)

## Review

### Loops

Loops are another form of branches (control flow statements). Loops allow for the repeated execution
of certain code. They too come in various shapes and forms.

#### While

A `while` loop is the simplest kind of loop which iterates *while* its condition evaluates to true.

```C++
while (boolean_condition)
{
    // Code to be repeated while the boolean_condition holds
}
```

#### Do-while

A `do-while` loop resembles a `while` loop with the major exception that it will always be executed
at least once, whereas a `while` may be iterated zero times.

```C++
do
{
    // Code to be done immediately and repeated the boolean_condition holds
}
while (boolean_condition); // <-- don't forget the semicolon here
```

#### For-loop

A `for` loop is a shortcut to one really common variant of `while` - when one has to cycle
for some usually predermined numbers of steps:

```C++
for (initialization_expression; boolean_condition; update_expression)
{
    // Code to be repeated for the time boolean_condition is true
}
```

##### Example

```C++
for (int i = 0; i < maxIterationCount; ++i)
{
    // Code to be executed
}
// Is precicely identical to
int i = 0;
while (i < maxIterationCount)
{
    // Code to be repeated
    ++i;
}
```

Notes:

* Prefer `for` to `while` to `do-while` when possible
* The three parts of the `for` loop (`initialization_expression`, `boolean_condition`, `update_expression`)
are optional
* Be careful when writing your loops not to introduce a case in which the `boolean_condition`
never becomes `false`. If that happens your program will never quit - it will be stuck in an
*infinite loop*.

#### Loop helper-keywords

There are two keywords used in conjuction with loops that ease working with loops.

##### Break

Break is used to...well, break the loop. It allows you to make an early exit from any
loop and only breaks the innermost one in case you have nested loops.

```C++
// This loop detects if n is the second power of some number
for (int i = 0; i < n; ++i)
{
    if (n == i * i)
    {
        // No point in iterating further because our work here is done
        break;
    }
}
```

##### Continue

Continue is used to skip to the next iteration of a loop and just as break works
only on the innermost loop.

```C++
// This loop computes the second power of all odd numbers
for (int i = 0; i < n; ++i)
{
    if (i % 2 == 0)
    {
        // Skip even numbers; this skip the code below and start the next iteration
        continue;
    }
    std::cout << i * i << " ";
}
```

### Arrays

The **array** is such a **data structure** that stores a fixed number of elements of a certain type.
Indexing of the arrays starts from `0`(first element) and goes to `n-1`(last element) where `n` is the size of the array.

#### Declaration

```
type arrayName[arraySize];
```

where **type** is any valid C++ data type, **arraySize** is an integer constant greater than zero.

##### Example

```
double heights[10];
```

#### Initializing

```
double heights[6] = { 3.2, 1, 10, 100, 5.5, 6 };
```

the number of elements cannot be more than we specified in the square brackets `[6]`.

#### Access and modify elements

Print element of the array:
```
cout << heights[0];
```
this will print the first element of the array which is `3.2`.

Modify element of the array:
```
heights[5] = 10; // this will change the last element of the array from 6 -> 10
cout << heights[5];
```

## Exercises

### Task 1 - Queries

Write a program that takes an array of real numbers and and a sequence of real numbers
each element of which is called a *query*. The program must
output up to what index in the array we need to sum all numbers to get a result bigger
than each *query*. In other words, for each query `q` the program must find that `x`
for which `array[0] + array[1] + ... + array[x] >= q`.


**Input:**

The first line contains `N` meaning the size of the array.
The next `N` lines contain each element of the array.
Next line contains `M` - the number of queries to be made.
The next `M` lines contain each query.

**Output:**

The output contains `M` lines each denoting the index up to
which we have to sum the real numbers or `-1` if this is not possible.

Example:

Input
```
4
1
2
3
4
2
3
11
```

Output
```
1
-1
```

### Task 2 - Powerset

Given a set of numbers, computer its powerset i.e. the set of all of its subsets.
Use its [characteristic vector](https://en.wikipedia.org/wiki/Indicator_vector) to represent
each subset. To generate each vector it's enough to iterate from 0 to 2^n.
Finally, you need to use bitmasks to check if an element is contained within the subset.

**Input:**

The first line contains the size of the set `N`. `N` will always be between 1 and 64.
The next line contains exactly `N` numbers - the elements of the set.

**Output:**

You are to output all subsets of the set, each on a new line, separating the numbers in each
subset with a single space. Print an empty line for the empty set.

**Example:**

Input

```
3
1 2 3
```

Output
```

1
2
3
1 2
1 3
2 3
1 2 3
```

### Task 7 - Bring on the math

A [binary relation over the set A](https://en.wikipedia.org/wiki/Binary_relation) is any subset of AxA.
You should've already learned that in your course of Discrete Mathematics. Binary relations can be
*reflexive*, *symmetrical* and *transitive*. Relations that are reflexive, symmetrical and transitive
at the same time are called *equivalence* relations. Your task is to tell, given a relation,
whether that relation posseses any of these properties.

The relations in your task are binary relations over A = [0, n) - the set of all
natural numbers less than `n` where `n` is given on the console. Your relation
will consist of a set of pairs R = { (x, y) | 0 <= x < n & 0 <= y < n}. The number of pairs
|R| will also be given on the console.

**Input**

The first line contains a single number `n`. This number determines the range `A = [0, n)` over
which we'll consider the relation.

The second line contains a single number - |R| - the number of pairs in the relation

Each of the next |R| lines will contain 2 numbers (x, y) - the elements of the pair.

**Output**

On the first line output the text "Reflexive? ", followed by a 1 if the relation is reflexive
and 0 otherwise.

On the second line output the text "Symmetrical? ", followed by a 1 if the relation is symmetrical
and 0 otherwise.

On the third line output the text "Transitive? ", followed by a 1 if the relation is transitive
and 0 otherwise.

On the forth line output the text "equivalence? ", followed by a 1 if the relation is an
equivalence relation and 0 otherwise.

**Example**

Here are 4 examples:

Input

```
5
8
1 1
1 2
2 1
2 4
1 3
2 3
1 4
2 2
```

Output

```
Reflexive? 0
Symmetrical? 0
Transitive? 1
Equivalence? 0
```

Explanation: the relation is a subset of [0, 5)x[0, 5) and contains the elements
R = {(1, 1), (1, 2), (2, 1), (2, 4), (1, 3), (2, 3), (1, 4), (2, 2)}, |R| = 8.
The relation is not reflexive because (0, 0), (3,3) and (4,4) are not in R.
The relation is not symmetrical because at the minimum (4, 2) is not in R.

------------

Input

```
3
7
0 0
1 1
2 2
0 1
1 0
1 2
2 1
```

Output

```
Reflexive? 1
Symmetrical? 1
Transitive? 0
Equivalence? 0
```

Explanation: R is not transitive because (0, 2) is not in R but it should be since
(0, 1) and (1, 2) are in R

-----------

Input

```
8
7
1 2
2 1
5 5
8 9
9 8
1 6
6 1
```

Output

```
Reflexive? 0
Symmetrical? 1
Transitive? 0
Equivalence? 0
```

-----------

Input

```
5
17
1 2
2 1
1 1
3 4
3 3
1 3
1 4
2 3
2 4
4 3
4 1
4 2
4 4
2 2
0 0
3 1
3 2
```

Output

```
Reflexive? 1
Symmetrical? 1
Transitive? 1
Equivalence? 1
```
