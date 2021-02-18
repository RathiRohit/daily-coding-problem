Problem: 131
---

`CodeChef` | [link](https://www.codechef.com/problems/SUDBOOKS)

---

As we all know, Sudhanva is fond of reading books and taking
photographs. His dad (after gifting him an iPad last birthday)
gifted him a custom-made bookshelf this birthday.

This shelf is made in such a way that books can be inserted
and removed only from the top. Books are placed one over the
other in that shelf. Now to remember each book, Sudhanva
develops an algorithm. He first writes a number in his iPad,
then takes a photo of that number in his DSLR and then pastes
that photograph on the cover of each book. Initially the
bookshelf is empty.

You have given `Q` queries of either of the two types

Type 1. `1, N` In this type of query Sudhanva places a book
with photo of number `N` on the top. You don't have to print
anything in this query.

Type 2. `−1` In this Query Sudhanva takes out the topmost
book, you have to print the number on the book he just took
out. If the shelf is empty and Sudhanva is trying to take
out a book, print `"kuchbhi?"` without quotes.
  
- First line will contain `Q`, number of queries
- Following `Q` lines will contain queries of one of the types
  mentioned:

Type 1: `1 N` This query specifies that Sudhanva places a
book with number `N` on it, at the top of the shelf.

Type 2: `−1` This query specifies that Sudhanva takes out the
topmost books from the shelf.

For each query of Type 2, print the number `N` on the book he
just took out, if the shelf was empty, and it was not possible
to take out a book, then print `"kuchbhi?"` (without quotes).
Each output should be printed on a new line.

Constraints:
```
1 <= Q <= 106
1 <= N <= 109
```

Example input:
```
5
1 2
1 45
-1
-1
-1
```

Example output:
```
45
2
kuchbhi?
```
