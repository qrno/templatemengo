# UnBDESC 2023

[Link para submeter as questões](https://codeforces.com/group/btcK4I5D5f/contest/442253)

## Jovem Aprendiz

Essa foi a questão com mais submissões da prova (151, ou 31.0%).
Foram 12 RTEs, 35 TLEs, 74 WAs e 30 ACs.

Muitos dos WAs foram causados por overflows, que podem ser resolvidos trocando `int` por `long long`.

Os TLEs foram causados pelo fato da solução "naive" não ser rápida o suficiente.
Se o monstro tem muita vida (como $10^{18}$) e os ataques são muito fracos (como $1$ ou $2$),
é necessária uma quantidade enorme de ataques para matar o monstro.

Um jeito de resolver isso é pré-calcular a soma dos danos dos $N$ ataques.
Digamos que o monstro tem $5000$ de vida e os $N$ ataques dão $17$ de dano no total.
Podemos ver que o mago usará um ciclo de todos seus ataques pelo menos $\lfloor5000/17\rfloor = 294$ vezes.
Depois disso resta $2$ de vida, e podemos ir aplicando os ataques um por um enquanto o monstro não morrer.

A quantidade de ataques que vai restar após retirarmos os ciclos completos é sempre menor ou igual à $n$,
pois a vida que sobra é menor que o dano de um ciclo de ataques.
Assim o loop que vai aplicando o dano de cada ataque enquanto o monstro estiver vivo não vai rodar mais
do que $N$ vezes, sendo rápido o suficiente.

Complexidade: $O(N)$

```cpp
#include <bits/stdc++.h>
using namespace std;

long long A[100'000 + 8];

int main() {
  long long n, m;
  cin >> n >> m;

  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    sum += A[i];
  }

  long long ans = (m/sum) * n;
  m %= sum;

  for (int i = 0; i < n; i++) {
    m -= A[i];
    ans++;
    if (m <= 0) break;
  }

  cout << ans << endl;
}
```
