# Compiling

```sh title="Compiling a.cpp into a"
g++ -Wall -Wextra -Wconversion -g3 -O3 -fsanitize=address,undefined a.cpp -o a
```

```sh title="Recording execution with valgrind"
valgrind --tool=cachegrind ./a < a.txt
```
