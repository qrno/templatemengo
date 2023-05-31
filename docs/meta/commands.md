# Commands

## Compiling

Sanitizers are _very_ useful. Always use them with `-g3`, which enables debug information.
It makes it so you can instantly know which line is causing your runtime error.

```console
g++ -Wall -Wextra -Wconversion -g3 -O3 -fsanitize=address,undefined a.cpp -o a
```

## Valgrind

```console
valgrind --tool=cachegrind ./a < a.txt
kcachegring kcachegrind cachegrind.out.XXXX
```

## Hashing

Hashes a file, ignoring all whitespace and comments.
Use for verifying that code was correctly typed.

```console
cpp -dD -P -fpreprocessed | tr -d '[:space:]'| md5sum | cut -c-6
```
