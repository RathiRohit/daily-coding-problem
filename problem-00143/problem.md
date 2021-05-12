Problem: 143
---

`CodeChef` | [link](https://www.codechef.com/MAY21B/problems/XOREQUAL)

---

For a given `N`, find the number of ways to choose an integer
`x` from the range `[0, 2^N−1]` such that `x⊕(x+1)=(x+2)⊕(x+3)`,
where `⊕` denotes the bitwise XOR operator.

Since the number of valid `x` can be large, output it modulo
`10^9+7`.

- The first line contains an integer `T`, the number of test
  cases.
- The only line of each test case contains a single integer `N`.

For each test case, output in a single line the answer to the
problem modulo `10^9+7`.

Constraints:
```
1 ≤ T ≤ 10^5
1 ≤ N ≤ 10^5
```

Example input:
```
2
1
2
```

Example output:
```
1
2
```

Explanation:
```
Test Case 1: The possible values of x are {0}.
Test Case 2: The possible values of x are {0,2}.
```
