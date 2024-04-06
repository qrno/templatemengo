# Checklist

## Is this <topic>?

- Binary Search on the answer
- Meet in the Middle
- Super greedy (make a wild guess)

## Thinking about solution

- Immediately play with the sample cases, you may have understood the problem wrong
- Think about constraints

## Before Submitting

- Even if the test cases pass, make sure your code is at least doing _something_
- If the test cases are _too_ simple, come up with an extra one
- Check constants are big enough
- Check time and memory limits
- Submit the right file

## General

- `#define int long long`
- Fast IO
- Be _very_ careful when copy pasting, check you've changed everything that needs changing
- Be wary of special cases, and when you do define one, be very sure you've correctly identified the full extent of their implications

## STL

- Check for empty when calling .back(), .front(), .top() on containers
- Don't change a container as you iterate through it (accessing a map may change it)
- Always make sure your iterators are valid
- When using multiset, don't use erase when you want to erase one!!!

## Graphs

- Add edges both ways if the graph is bidirectional
- On problems where you remove stuff, just do it backwards.

## Beecrowd/UVa

- Don't put space at the end of output
- Check if there are multiple testcases

## DP

- Try to invert the order of the states - sometimes the problem becomes much easier
- Can you use D&C DP?
- Can you use Convex Hull Trick?

## Small to Large

- Check if the `S[small] > S[big]` is not inverted

## SQRT

- It's hard to debug problems with SQRT "blocking".
If the block size is too big the mistakes won't show in the samples.
Change to a small block to check.

## Games

- Sprague-Grundy
- Symmetry
- Code something that calculates for small cases and find a pattern
