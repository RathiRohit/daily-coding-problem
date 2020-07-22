Problem: 60
---
You are given a string representing the initial conditions of
some dominoes.

Each domino can take one of three values:

`L` : meaning the domino has just been pushed to the left,

`R` : meaning the domino has just been pushed to the right,

`.` : meaning the domino is standing still.

Determine the orientation of each tile when the dominoes stop
falling.

Note that if a domino receives a force from the `left`
and `right` side simultaneously, it will remain upright.

For example,

Given the string `.L.R....L`, you should return `LL.RRRLLL`.

Given the string `..R...L.L`, you should return `..RR.LLLL`.
