---
math: mathjax
---

# 0763: Amobeas in a 3D Grid

Consider a three dimensional grid of cubes.
An amoeba in cube $(x, y, z)$ can divide itself into three amoebas
to occupy the cubes $(x + 1, y, z)$, $(x, y + 1, z)$ and $(x, y, z + 1)$,
provided these cubes are empty.

Originally there is only one amoeba in the cube $(0, 0, 0)$.
After $N$ divisions there will be $2N + 1$ amoebas arranged in the grid.
An arrangement may be reached in several different ways but it is only counted once.
Let $D(N)$ be the number of different possible arrangements after  divisions.

For example, $D(2) = 3$, $D(10) = 44499$, $D(20) = 9204559704$,
and the last nine digits of $D(100)$ are $780166455$.

Find $D(10000)$, enter the last nine digits as your answer.

<!--
Only thing i dont understand, what do they mean by "arrangements"?
It seems that the division process is deterministic,
with the amoebas continually dividing outward.
It HAS to divide into 3 possible spaces.

One possibility, that if one point would be occupied by two different divisions,
then that could count as two different "arrangements"?
Since they are being spawned from different amoebas.
-->

<!-- ## Initial definitions

For the rest of this problem,
instead of writing "amoebas", we are going to write "cells".

The problem says
"after $N$ divisions there will be $2N + 1$ *cells* arranged in the grid".
When we divide a given cell, we add three new cells but delete the original cell,
so overall two new cells are added.
Let
$$
C(N) \coloneqq 2N + 1
$$
be the total number of cells after $N$ divisions.

We now consider the number of *non-unique* arrangements after $N$ divisions,
which we will call $A(N)$.
This number can be determined recursively.
Let's start with $N = 1$, which divides $(0, 0, 0)$
into $(1, 0, 0)$, $(0, 1, 0)$, and $(0, 0, 1)$.
There is a single arrangement of size $C(1) = 3$,
so $A(1) = 1$.

If we move on to $N = 2$,
*we will go on to divide each of the three cells*,
and each division will result in a different arrangement.
There will now be three different arrangements,
each of length $C(2) = 5$.
In other words,
to get $A(2)$, we have to divide each of the $C(1)$ cells
from all of the $A(1)$ previous arrangements,
so $A(2) = C(1) \cdot A(1) = 3$.

Let's check $N = 3$ before generalizing;
for a given arrangement (of which there are three),
there are five cells.
For each of these five cells, we can divide one
and get a new arrangement of seven cells.
Each of the $A(2)$ arrangements will have $C(2)$ cells
that can be divided,
so there are a total of $A(3) = C(2) \cdot A(2) = 5 \cdot 3 = 15$ new arrangements.

In general, when looking at $A(N)$,
ther will be $A(N - 1)$ arrangements of $C(N - 1)$ cells,
giving a total of
$$
A(N) = C(N - 1) \cdot A(N - 1)
$$
arrangements.
We can also write this as
$$
A(N)
= C(N - 1) \cdot A(N - 1)
= C(N - 1) \cdot C(N - 2) \cdot A(N - 2)
= \cdots
= \prod_{n = 0}^{N - 1} C(n).
$$
This product actually has a closed form formula:
$$
A(N)
= \prod_{n = 0}^{N - 1} C(n)
= \prod_{n = 0}^{N - 1} (2n + 1)
= \frac{(2N)!}{2^N \cdot N!}.
$$
Although we will not use it directly,
the presence of the factorials shows that the values of
$A(N)$ will grow very quickly
(which we can see from some of the test cases provided by the problem).

Again, this is the number of *non-unique* arrangements.
What we want is the number of *unique* arrangements,
which we will call $D(N)$.
Since a given set of arrangements might not have any repeats,
we have $D(N) \le A(N)$.
Actually determining $D(N)$ is the heart of this problem.

## Division -->

<!--
Summarized results with new understanding:
- Each "path" to get to a certain arrangement of cells is unique.
- When dividing cells, cannot divide two cells that are adjacent to each other.
Because there would be overlap, and that is not allowed.
- Specifically, if a cell is divided into three new cells on the next level,
only one of those next cells could potentially be divided at a time.
- But its not limited to spawns of one cell.
Could have two offspring from different cells that would result in intersection.
- Probably best to just loop through and make sure that there is no intersection.
- This problem is naturally a recursive one.
The initial recursion we defined initially is still correct,
its just not algorithmically viable anymore (I think).

How could we recurse?
1. Could recuse based off number of divisions.
But this means we would have to keep track of all orientations
for N - 1, and then divide for N.
That seems computationally infeasible due to storage.
2. Recurse based on "level", the depth along the simplex.
We could input the number of divisions remaining,
then recursively call the count function on the next level.

It's tricky though to make sure we are not selecting cells that would result in an overlap.
So we would have to say
- we have this many cells left to divide
- select a certain amount of cells (from 1 to min(remaining divisions, number of cells at this level))
- find all valid combinations of these cells
- "recurse" by dividing these cells out and repeating on the next level

jesus i wonder how long this will take

so the next step is choosing the proper data structures to represent everything.
this may take a long time to compute.
may have to reach for C++ for this one.
we can write prototype and check answers against test cases provided by question.

also because the numbers are so large, only looking at last 9 digits.
but i think this is okay, just mod the output by 1 billion and that will be fine.
we should test that this is okay.
Yeah, this seems okay.

Later we will re-look at written info above.
I don't think its wrong, its just we will not go about constructing the recursion in this way.
Will have to think better about how to construct it then.

-->