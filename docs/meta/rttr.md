# RTTR

## About

### Theory

Rounds will be held on the [Vjudge Group](https://vjudge.net/group/flamengo).

After doing 100 rounds of these, you will get the Grandmaster on Codeforces.
It is 100% guaranteed, trust me.

I'll try to do these often and post little hints and solutions afterwards.

## [RTTR #1](https://vjudge.net/contest/575522#overview)

Result:

 - [ ] [Fib-Tree](https://codeforces.com/problemset/problem/1491/E)
 - [X] [Are You Fired?](https://codeforces.com/problemset/problem/1358/E)
 - [X] [DeadLee](https://codeforces.com/problemset/problem/1369/E)

Didn't solve the first problem because of a silly implementation mistake.
(Granted I did overcomplicated a little).

Overall really great problems, highly recommend solving all of them.

### Fib-Tree

??? info "Hint 1"
    For a given Fibonacci number, there is a single way of decomposing it into smaller Fibonacci numbers.

??? info "Hint 2"
    For a given tree of fibonacci size, there are at most two ways of decomposing it into smaller trees of fibonacci size.
    ??? info "Hint 2.1"
        It doesn't matter which of the ways you pick.

??? success "Solution"
    - Create some function `fibtree(v)` which will return a bool if the tree that contains v is a Fib-Tree.
    - Root the tree in v and get all the subtree sizes.
    - Iterate through the tree until you find someone with size $F_{i-1}$ or $F_{i-2}$.
    - Remove the edge connecting that vertex to its parent.
        - This is possible by making G a `vector<set<int>>`
    - When you get to a subtree of size at most 3, return true.

??? quote "Thoughts"
    - Really great problem, but it pretty easy to guess the solution without understanding why it works.
    - I ended up using the trees' centroids, which wasn't too bad but unnecessary.
    - Silly implementation mistake, was returning too eagerly in the `get_need` function.

### Are You Fired?

??? info "Hint 1"
    If a solution with some length works. A solution with double that length also works.

??? info "Hint 2"
    That means that there is a solution with length at least $N/2+1$.

??? info "Hint 3"
    That makes the case $X > 0$ really easy.
    ??? info "Hint 2.1"
        Just pick N. Check if that works.

??? success "Solution"
    - We're down to the case $X \leq 0$ and we know the length is at least $N/2+1$.
    - Document for each position from the first half how long the range starting at it can be.
    - The length must be at least $N/2+1$. As the range grows the sum decreases, so it is a prefix.
    - Therefore we can binary search for that.
    - To check if some length len works overall,
      check if all the indices where ranges would be starting can handle ranges that big.

??? quote "Thoughts"
    - Did this problem pretty quickly.
    - Did the right choice of dividing it into cases and analysing.

### DeadLee

??? info "Hint 1"
    Work with the concept of having "enough" of a given food.
    Count how many people want each food.
    You have enough of it if you have more of it than people want.

??? success "Solution"
    - What can you do if you have enough of some food $f$?
        - Give it to everyone who wants it, then remove these people.
        - By "remove" I mean put them in the back of the order and make them "not want" the rest of the food.
        - You can do that by keeping a `vector<set<int>>` with the people that want each food.
    - If by removing people you now have enough of some other food, put that food on the queue and repeat the process.
    - It is kinda like a BFS
    - [Implementation](https://codeforces.com/contest/1369/submission/218847863) for reference

??? quote "Thoughts"
    - Really nice problem but also quite easy. Not sure why it is rated 2400.
    - Once you create the concept of having "enough" of some food the solution flows pretty naturally.
