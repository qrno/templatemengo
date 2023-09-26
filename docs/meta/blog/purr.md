Available on [Codeforces](https://codeforces.com/blog/entry/117138).
Pretty simple technique but found it useful a couple times.


# Purr =^..^= Packing Under Range Regulations

This is a simple and educational greedy solution to an AtCoder problem.

The following is [(abc214_e) Packing Under Range Regulations](https://atcoder.jp/contests/abc214/tasks/abc214_e): (slightly modified)

## Problem Statement

There are $10^9$ boxes numbered $1, 2, \ldots, 10^9$ and $N$ balls numbered $1, 2, \ldots, N$.

Each box can contain at most one ball.

Determine whether it is possible to put all $N$ balls in the boxes so that the following condition will be satisfied.

- For each integer $i$ from $1$ through $N$, the ball numbered $i$ is in a box numbered between $L_i$ and $R_i$ (inclusive).

### Constraints

- $1 \leq N \leq 2 \times 10^5$
- $1 \leq L_i \leq R_i \times 10^9$

## How to solve it

I suggest you try your best to solve the problem before continuining.

### My initial solution

Initially, I tried a
[more complicated solution](https://atcoder.jp/contests/abc214/submissions/37551484)
based on
[Hall's Marriage Theorem](https://en.wikipedia.org/wiki/Hall%27s_marriage_theorem).
However, the problem's editorial outlines a much more elegant solution that we will discuss.

### Visualizing the Problem

Imagine you're walking along the boxes from $1$ to $10^9$ without turning back.
Some of the boxes may have people behind them, each holding a ball to give you.
The person with ball $i$ is behind box $L_i$.
Whenever you encounter a person, you take the ball they're holding.

At any moment you can place any ball you're holding into the box in front of you,
including the one just given to you.
However, each box can only hold one ball.

But there's a twist: each ball is actually a ticking bomb.
Ball $i$ is a bomb that will explode and kill you if you don't put it into a box
before passing position $R_i$.

### Understanding the Greedy

The story above is equivalent to the initial problem statement,
but presenting it like this helps make the greedy solution more intuitive.

There's never a point in leaving a box empty if you're holding any bombs.
You won't be able to come back to it later and leave a bomb there,
so you might as well take some weight off your back right now.
However, you still have a choice to make: which of the bombs should you discard?

For example, imagine you're holding three bombs that will explode at times $7$, $8$, and $10$.
You can discard a single bomb. Which one should you choose?

The correct approach is to always get rid of the bomb closest to exploding.
Although this may not be strictly necessary, there's no reason not to do it.
It's intuitive to see how this is correct, but let's provide a proof for completeness:

### Proof

Consider a configuration of bomb choices where no bombs explode.
Let's say that at some point, instead of discarding the bomb closer to exploding,
denoted as $X$, you discard some other bomb $Y$ that would explode later.
You only discard $X$ at a later time.

If we switch the positions of bombs $X$ and $Y$, we would still have a valid configuration.
$X$ would be discarded earlier than before, so it clearly still wouldn't explode.
$Y$ would be discarded later,
but it would be discarded in position where $X$ still wouldn't have exploded,
and $X$ explodes earlier than $Y$.

With this switch, we obtain a configuration with less "inversions",
meaning there are fewer positions where we chose the "wrong" bomb.
By repeating this process,
we can transform any valid configuration into the one we would get using our greedy approach,
without ever making it invalid.
Therefore, if a solution exists, our greedy approach is a valid solution.

### Implementation

The implementation consists of simulating the situation described above,
resulting in an $\mathcal{O}(N\log N)$ solution.
The $\log N$ factor comes from sorting the balls in our inventory, for example, using a priority queue.

We start from position $1$ and iterate through the positions up to $10^9$,
taking any balls we encounter and discarding them as possible.
Always picking the bomb closer to exploding.
If any bomb explodes, there's no solution.

It is important to note that if our inventory is empty,
we should skip to the next box where you'll be given a ball.

If you get stuck, refer to the problem's [editorial](https://atcoder.jp/contests/abc214/editorial/2446),
where a nice implementation can be found.

## Other problems

Here are two problems that can be solved if you're able to reduce them to Purr:

- [(agc008_d) Kth-K](https://atcoder.jp/contests/agc008/tasks/agc008_d)
- [(CF555_b) Case of Fugitive](https://codeforces.com/problemset/problem/555/B)

Curiously, a few days after I wrote this blog, this technique showed up in an AtCoder Beginner Contest:

- [(abc304_h) Constrained Topological Sort](https://atcoder.jp/contests/abc304/tasks/abc304_h)
