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

Complexidade: $\mathcal{O}(\log_\varphi R)$? É tão rápido que nem importa

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

## Interruptores

Para simplificar o código, convertemos os valores do vetor de $(1, 0, -1)$ para $(0, 1, 2)$.

Fazemos uma DP que guarda para $(i, j)$ o menor custo para obter $A_0 \dots A_i$ com $A_i = j$.
A DP é baseada do fato que para obter $A_0 \dots A_i$, devemos primeiro obter
$A_0 \dots A_{i-1}$ com $A_{i-1} = j \text{ ou } j-1$ e depois adicionar $A_i = j$.
Devemos somar o custo $1$ para mudar o estado do interruptor caso $A_i \neq j$.

Para $i=0$ temos os casos base: $D_{(0,0)} = A_0 \neq 0, D_{(0, 1)} = \infty, D_{(0, 2)} = \infty$.

Para $i>0$, temos:

$$
D_{(i, j)} = min
\begin{cases}
    D_{(i-1, j)}\\
    D_{(i-1, j-1)} \text{ para } j > 0
\end{cases}
+ (A_i \neq j)
$$

Complexidade: $\mathcal{O}(N)$

```cpp
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int n;
int A[100'000 + 8];
int DP[100'000 + 8][3];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    if (A[i] == +1) A[i] = 0;
    else if (A[i] ==  0) A[i] = 1;
    else if (A[i] == -1) A[i] = 2;
  }

  DP[0][0] = (A[0] != 0);
  DP[0][1] = DP[0][2] = INF;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      DP[i][j] = DP[i-1][j] + (A[i] != j);
      if (j-1 >= 0) {
        DP[i][j] = min(DP[i][j], DP[i-1][j-1] + (A[i] != j));
      }
    }
  }

  cout << DP[n-1][2] << endl;
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

Complexidade: $\mathcal{O}(N)$

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

## Keyboard

O enunciado não garante que não vão ter dois números iguais seguidos na sequência de digitação. O jeito mais fácil de lidar com isso é quando for ler a sequência ignorar os números que são iguais ao número anterior.

Depois disso é só fazer uma BFS, onde em vez do estado ser $(i, j)$, ele é $(i, j, \text{done})$, onde $\text{done}$ é a quantidade de itens da sequência que já foram satisfeitos. O código abaixo é bem auto-explicativo.

Complexidade: $\mathcal{O}(N\cdot M\cdot Q)$

```cpp
#include <bits/stdc++.h>
using namespace std;

const vector<pair<int, int>> delta{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector grid(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> grid[i][j];

  int q; cin >> q;
  vector<int> path;
  for (int i = 0; i < q; i++) {
    int x; cin >> x;
    if (path.empty() || path.back() != x)
      path.push_back(x);
  }
  q = size(path);

  vector dist(n, vector(m, vector<int>(q+1, -1)));

  queue<array<int, 4>> Q;

  int first_done = path[0] == grid[0][0];
  Q.push({0, 0, 0, first_done});

  while (!Q.empty()) {
    auto [vd, vi, vj, vdone] = Q.front(); Q.pop();
    if (vdone == q) return cout << vd << endl, 0;

    for (auto [di, dj] : delta) {
      int ui = vi + di, uj = vj + dj;
      if (!(0 <= ui && ui < n)) continue;
      if (!(0 <= uj && uj < m)) continue;

      int udone = vdone + (grid[ui][uj] == path[vdone]);
      if (dist[ui][uj][udone] == -1) {
        dist[ui][uj][udone] = vd + 1;
        Q.push({vd+1, ui, uj, udone});
      }
    }
  }
}
```
