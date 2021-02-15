Problem: 130
---

`CodeChef` | [link](https://www.codechef.com/problems/EQSBSTR1)

---

You are given two strings `A` and `B` of lengths `N` and
`M` respectively. Find the maximum length of a substring
of `A` that is also present in `B`.

Let this maximum length be `K`. Also, find all such
substrings of length `K` that is present in both `A` and
`B` and print the number of times each such a substring
occurs in `B`.

- First line contains a single integer `T`, the number of
  test cases.
- First line of each test case contains two space-separated
  integers, `N` and `M`.
- Second line of each test case contains two space-separated
  strings, `A` and `B`.

For each test case, output in the first line `K`,
the maximum length of a common substring. Then follows `X`
lines of output, where `X` denotes the number of substrings
in `A` of length `K` that is also present in `B`.

In each such line, print the substring of length `K`
present in both the strings, and the number of times that
substring occurs in `B` (separated by a single space).

The substrings must follow a lexicographic order, i.e.,
you must first print the substring that will occur earlier
in a dictionary than the others.

Constraints:
```
1 <= T <= 100
1 <= N,M <= 20
Sum of N over all test cases doesn't exceed 103
Sum of M over all test cases doesn't exceed 103
All strings consist of lowercase latin letters only
```

Example input:
```
4
14 17
pqfwkhopkmcoqh yggxxpklorellnmpa
1 16
q bcnuvqhffbsaqxwp
4 20
rxsj owkkyhiddqscdxrjmowf
6 7
drrwso qfjmafa
```

Example output:
```
2
pk 1
1
q 2
1
j 1
r 1
s 1
x 1
0
```
