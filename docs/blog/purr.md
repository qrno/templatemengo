# Purr

This is a description of really educational greedy solution to an AtCoder problem. It may be obvious to some of you, but given the problem is rated 1835 on AtCoder, which is equivalent to 2100 on Codeforces, I'd say it is a relatively challenging problem.

The following is [(abc214_e) Packing Under Range Regulations](https://atcoder.jp/contests/abc214/tasks/abc214_e) with a very slightly modified statement:

## Problem Statement

There are $10^9$ boxes numbered $1, 2, \ldots, 10^9$ and $N$ balls numbered $1, 2, \ldots, N$.

Each box can contain at most one ball.

Determine whether it is possible to put all $N$ balls in the boxes so that the following condition will be satisfied.

- For each integer $i$ from $1$ through $N$, the ball numbered $i$ is in a box numbered between $L_i$ and $R_i$ (inclusive).

### Constraints

- $1 \leq N \leq 2 \times 10^5$
- $1 \leq L_i \leq R_i \times 10^9$

## How to solve it

I suggest you try your best to solve the problem so you can may get familiar with its challenges.

### My bad solution

When I first read this problem I was reminded of [Hall's Marriage Theorem](https://en.wikipedia.org/wiki/Hall%27s_marriage_theorem), which led to a [very convoluted solution](https://atcoder.jp/contests/abc214/submissions/37551484) involving lazy segment trees and ordered sets.
But this isn't the solution we'll discuss, since the problem's editorial outlines a much more elegant solution which I've found useful many times since.

### Story

You walk along the boxes, from $1$ to $10^9$. Never turning back.
Behind some of the boxes there may be one or more people, each holding a ball, which they want to hand off to you.
The person with ball $i$ is behind the box $L_i$.
If you meet a person, you _need_ to take the ball they're holding.

At any moment you can put any of the balls you're holding inside of the box in front of you. You can even put in the ball the person is behind the box just gave you. But the box only holds a _single_ ball.

But there is a problem, each ball is actually a ticking bomb. More specifically, ball $i$ is a bomb that will kill you if you don't put it into a box by the time you're past position $R_i$.

### What it means

I hope it is clear how the story above is equivalent to the initial problem. I like framing the problem like this because it makes it much clearer what you're supposed to do.

There's never a point in leaving a box empty if you're holding any bombs. You won't be able to come back to it and get rid of some future bomb anyways. Might as well take some weight off your back. But you do have a choice in this problem: which of the bombs to discard.

Now imagine you're at box $6$, and you're holding three bombs which are going to explode at times $7$, $9$ and $10$.
You can get rid of a single one of them. Which bomb do you get rid of?
I _really_ hope the answer is clear or else I hope you don't find yourself with multiple ticking bombs.

You will always want to get rid of the bomb that is closer to exploding.
Sometimes this isn't absolutely necessary, but it would be silly not to. Getting rid of it gives you the best chance of survival.

### Implementation

Just simulating the situation above will give you an $\mathcal{O}(N\log N)$ solution. The $\log$ comes from sorting the balls in your inventory (with a priority queue for instance).

Go through the positions from $1$ to $10^9$ getting any balls you come across and getting rid of them as you can. If any bomb explodes you lose.

It is also important that if you don't have any balls in your inventory you skip to the next person that will give you a ball.

If you do get stuck, reference the problem's [editorial](https://atcoder.jp/contests/abc214/editorial/2446).

## Other problems

Here are two problems that can be solved if you're able to reduce them to Purr:

- [(agc008_d) Kth-K](https://atcoder.jp/contests/agc008/tasks/agc008_d)
- [(CF555_b) Case of Fugitive](https://codeforces.com/problemset/problem/555/B)
