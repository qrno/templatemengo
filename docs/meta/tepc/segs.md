# Aula de Segs

[Contest no vjudge](https://vjudge.net/contest/680959)

# Guia

# Andar na Seg

A ideia é você "andar" na seg pra fazer alguma query,
em vez de só chamar "update" e "query".

No problema, a gente tem uma seg de soma e quer achar a
posição mais a esquerda que tem valor pelo menos x.
Dá pra implementar assim:

```cpp
int at_least(int x, int id, int il, int ir) {
  if (T[id] < x) return -1;
  if (il == ir) return il;

  int im = midpoint(il, ir);
  if (T[2*id] >= x) return at_least(x, 2*id, il, im);
  else return at_least(x, 2*id+1, im+1, ir);
}
```

# Seg com Lazy Propagation

É pra updates em range, tipo "somar x em todos os elementos de L até R".
A ideia é ter tipo um vetor secundário (lazy) que guarda em cada posição da seg
uma "flag" como "quanto falta somar nos elementos desse nó".

E aí fazer uma função _push_ que aplica essa flag e aí repassa ela para os filhos.
Você chama esse push toda vez que entrar em um nó, tanto no update quanto na query.

```cpp
vector<int> T, L;

void push(int id, int il, int ir) {
  T[id] += (ir-il+1) * L[id];
  if (il != ir) {
    L[2*id] += L[id];
    L[2*id+1] += L[id];
  }
  L[id] = 0;
}

void update(int l, int r, int x, int id, int il, int ir) {
  push(id, il, ir);

  if (r < il || ir < l) return;
  if (l <= il && ir <= r) {
    L[id] += x;
    push(id, il, ir);
    return;
  }

  int im = midpoint(il, ir);
  update(l, r, x, 2*id, il, im);
  update(l, r, x, 2*id+1, im+1, ir);

  T[id] = T[2*id]+T[2*id+1];
}

int query(int l, int r, int id, int il, int ir) {
  push(id, il, ir);

  if (r < il || ir < l) return 0;
  if (l <= il && ir <= r) return T[id];

  int im = midpoint(il, ir);
  return query(l, r, 2*id, il, im)
       + query(l, r, 2*id+1, im+1, ir);
}
```

A gente também viu a versão desse problema que além da soma ele tem
o set ("coloque x em todos os valores de L até R").

Pra esse você vai ter um lazy um pouco diferente.
Você guarda um pair {a, b} que significa
"transformar os elementos desse range em ax+b".

# Seg Esparsa

Basicamente uma seg mas com um número bem maior de posições.
Você pode por exemplo criar uma seg com posições de 1 até 10^18.
Numa seg normal você precisaria de tipo 10^18 posições pra isso,
mas na seg esparsa ele só cria de verdade os nós que ele "toca".

A maioria dos problemas dá pra fazer de forma mais simples com
compressão de coordenada.

Aqui é a implementação com ponteiro:

```cpp
const int SZ = 1e9 + 8;

struct Node {
  int sum = 0;
  Node *L, *R;

  void add(int idx, int val, int il=0, int ir=SZ-1) {
    if (il == ir) {
      sum += val;
      return;
    }

    int im = midpoint(il, ir);
    if (idx <= im) {
      if (!L) L = new Node();
      L->add(idx, val, il, im);
    } else {
      if (!R) R = new Node();
      R->add(idx, val, im+1, ir);
    }

    sum = 0;
    if (L) sum += L->sum;
    if (R) sum += R->sum;
  }

  int query(int l, int r, int il=0, int ir=SZ-1) {
    if (r < il || ir < l) return 0;
    if (l <= il && ir <= r) return sum;

    int im = midpoint(il, ir);
    int ans = 0;
    if (L) ans += L->query(l, r, il, im);
    if (R) ans += R->query(l, r, im+1, ir);
    return ans;
  }
};

// pra usar:

auto seg = new Node();
seg->add(10, +5);
cout << seg->query(2, 5) << endl;
```

# Seg Persistente

É uma seg que você não perde nada.
É como se cada update criasse uma seg nova

Você pode fazer updates em uma seg e depois poder
voltar e fazer queries e updates diferentes na seg antiga.

Aqui tem uma implementação com "índice", de uma seg de mínimo.
Deve ser parecida com a que vocês devem ter visto pra "tries" na aula de string.
Acho que lendo a implementação com calma dá pra entender como funciona.

```cpp
const int INF = 1e9;

const int MAXN = 5e5 + 5;
struct Node { int mini, L, R; };

// !!! É bom pensar bastante em quanto tem que ser o tamanho desse vetor
array<Node, 22 * MAXN> T;
int CNT = -1;

int new_node(int val = INF) {
  T[++CNT] = {val, -1, -1};
  return CNT;
}

int merge_nodes(int l, int r) {
  T[++CNT] = {min(T[l].mini, T[r].mini), l, r};
  return CNT;
}

int build(int il, int ir) {
  if (il == ir) return new_node();

  int im = midpoint(il, ir);
  return merge_nodes(build(il, im),
                     build(im+1, ir));
}

int query(int node, int l, int r, int il, int ir) {
  if (r < il || ir < l) return INF;
  if (l <= il && ir <= r) return T[node].mini;

  int im = midpoint(il, ir);
  return min(query(T[node].L, l, r, il, im),
             query(T[node].R, l, r, im+1, ir));
}

int update(int node, int idx, int x, int il, int ir) {
  if (idx < il || ir < idx) return node;
  if (il == ir) return new_node(x);

  int im = midpoint(il, ir);
  return merge_nodes(update(T[node].L, idx, x, il, im),
                     update(T[node].R, idx, x, im+1, ir));
}

// pra usar:
int seg_velha = build(0, N-1);
int seg_nova1 = update(seg_velha, 3, 5, 0, N-1);
int seg_nova2 = update(seg_nova1, 4, 7, 0, N-1);

cout << query(seg_velha, 2, 3, 0, N-1) << endl;
cout << query(seg_nova1, 2, 3, 0, N-1) << endl;
cout << query(seg_nova2, 2, 3, 0, N-1) << endl;
```
