# UnBDESC 2023

[Link para submeter as questões](https://codeforces.com/group/btcK4I5D5f/contest/442253)

## Fibonacci String

Podemos pré-calcular facilmente quantas letras temos em $F_0, F_1, F_2\dots$, esse será o vetor `AB` abaixo.
Também guardaremos o tamanho de cada uma dessas palavras em `LEN`.

Queremos saber as quantidades de $a$ e $b$ em $\mathcal{F}[L, R]$.
Podemos fazer isso conseguindo essas quantidades em $\mathcal{F}[0,R]$ e removendo as quantidades em $\mathcal{F}[0,L-1]$.

Quando pegamos um prefixo de $\mathcal{F}$, vamos pegar várias strings completas, mais um prefixo de uma palavra que ficou incompleta. Fazemos isso na função `ab_count`, que adiciona as letras de palavras completas enquanto o total não ultrapassa a quantidade de letras que queremos. No fim, ela chama a função `word_prefix` que acha a quantidade de cada letra num prefixo dessa palavra incompleta.

A função `word_prefix` tem dois casos base. Se o prefixo que queremos tem tamanho $0$, as quantidades são $0$. Além disso, criamos casos especiais para a primeira e a segunda palavra.

O principal fato que deve ser notado é que como $F_k = F_{k-1} \oplus F_{k-2}$, se temos um prefixo de $F_k$ que é menor ou igual à $F_{k-1}$, ele é equivalente à um prefixo do mesmo tamanho de $F_{k-1}$. Senão, ele é $F_{k-1}$ por completo, mais um prefixo de $F_{k-2}$. Assim, podemos definir `word_prefix` recursivamente de uma forma simples.

```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long

pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
  return {a.first + b.first, a.second + b.second};
}

const int MAXF = 86;
pair<int, int> AB[MAXF];
int LEN[MAXF];

pair<int, int> word_prefix(int idx, int len) {
  if (len == 0) return {0, 0};
  if (idx == 0 || idx == 1) return AB[idx];
  if (len <= LEN[idx-1]) return word_prefix(idx-1, len);
  return AB[idx-1] + word_prefix(idx-2, len-LEN[idx-1]);
}

pair<int, int> ab_count(int prefix_len) {
  int idx = 0;
  int len = 0;
  pair<int, int> ab{0, 0};

  while (len + LEN[idx] <= prefix_len) {
    ab = ab + AB[idx];
    len += LEN[idx];
    idx++;
  }

  int left = prefix_len - len;
  return ab + word_prefix(idx, left);
}

signed main() {
  AB[0] = {0, 1}; LEN[0] = 1;
  AB[1] = {1, 0}; LEN[1] = 1;
  for (int i = 2; i < MAXF; i++) {
    AB[i] = AB[i-1] + AB[i-2];
    LEN[i] = LEN[i-1] + LEN[i-2];
  }

  int l, r;
  cin >> l >> r;

  auto [ra, rb] = ab_count(r+1);
  auto [la, lb] = ab_count(l);

  cout << ra-la << ' ' << rb-lb << endl;
}
```

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

A quantidade de ataques que vai restar após retirarmos os ciclos completos é sempre menor ou igual à $N$,
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
