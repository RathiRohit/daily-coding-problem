Problem: 140
---

`CodeChef` | [link](https://www.codechef.com/problems/MRGSRT)

---

You must be aware of the sorting technique, called merge
sort where we sort an input array by first dividing it into
two halves, and then sorting the each half recursively
before finally merging these sorted halves.

A GEU student, Mohan want to understand this recursive
algorithm more clearly and is interested to know how the
recursive function calls are getting called during the merge
sort program execution for the given input parameters -
input array (`A`), begin index (`s`) and the end index (`t`).

When the function `merge_sort(A,s,t)` is called, the
recursive functions calls would be executed as per the input
parameters. Mohan is interested to take a snapshot of the
function calling stack when `merge_sort(A,i,i)` is being
executed, where `s <= i <= t`. Mohan also wants to know the
recursive function depth at that point of time.
Assume that, if the input array consists of odd number of
elements then it is divide in such a way that the left half
contains one element more than the right half.

- The first line of input contains `T`, the number of test
  cases.
- T lines follow, each line containing three values
  corresponding to `s`, `t` and `i`.

For each test case, output in separate lines, the begin
and end index input parameters of the `merge_sort()` that
would have been called till it reaches sorting `i`th
index element. Mention these in same sequence as the
function calls were called, and also then include in the
next line the recursive function depth at that time.
Return `-1` if it could not have been called.

Constraints:
```
1 ≤ T ≤ 1000
1 ≤ t ,i ≤ 1000
0 ≤ s ≤ 1000
```

Example input:
```
4
0 4 3
7 15 14
1 16 9
7 14 3
```

Example output:
```
0 4
3 4
3 3
3
7 15
12 15
14 15
14 14
4
1 16
9 16
9 12
9 10
9 9
5
-1
```

Explanation for first test case:
```
If we take the snapshot of the function calling stack when
merge_sort(A,3,3) would have been called during the
execution of merge_sort(A,0,4), then there would be seen -
the function merge_sort(A,0,4) calling merge_sort(A,3,4),
which would then be calling merge_sort(A,3,3). So, in this
case, the recursive depth would be 3.
```
