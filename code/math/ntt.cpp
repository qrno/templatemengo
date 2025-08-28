// NTT {{{
const int MOD = 998'244'353; // 7*17*2^23 + 1
const int G = 3;
const int ROOT_23 = 15311432; // G ^ (7 * 17)
const int ROOT_23_INV = 469870224; // ROOT_23 ^ -1
const int ROOT_POW = (1 << 23);

int fexp(int b, int e) {
  int ans = 1;
  while (e) {
    if (e & 1) ans = ans * b % MOD;
    e >>= 1;
    b = b * b % MOD;
  }
  return ans;
}

int multinv(int x) {
  return fexp(x, MOD-2);
}

void fft(vector<int> &A, bool invert) {
  int N = A.size();

  for (int i = 1, j = 0; i < N; i++) {
    int bit = N/2;
    while (j & bit) j ^= bit, bit >>= 1;
    j ^= bit;
    if (i < j) swap(A[i], A[j]);
  }

  for (int len = 2; len <= N; len <<= 1) {
    int wlen = invert ? ROOT_23_INV : ROOT_23;
    for (int i = len; i < ROOT_POW; i <<= 1)
      wlen = (wlen * wlen) % MOD;

    for (int i = 0; i < N; i += len) {
      int w = 1;
      for (int j = 0; j < len/2; j++) {
        int u = A[i+j];
        int v = A[i+j+len/2] * w % MOD;
        A[i+j] = u + v;
        if (A[i+j] >= MOD) A[i+j] -= MOD;
        A[i+j+len/2] = u - v;
        if (A[i+j+len/2] < 0) A[i+j+len/2] += MOD;
        w = w * wlen % MOD;
      }
    }
  }

  if (invert) {
    int N_INV = multinv(N);
    for (auto &x : A) x = x * N_INV % MOD;
  }
}

vector<int> multiply(vector<int> const& A, vector<int> const& B) {
  vector<int> fa(begin(A), end(A)), fb(begin(B), end(B));
  int N = 1;
  while (N < A.size() + B.size()) N <<= 1;
  fa.resize(N);
  fb.resize(N);

  fft(fa, false);
  fft(fb, false);
  for (int i = 0; i < N; i++)
    fa[i] = fa[i] * fb[i] % MOD;
  fft(fa, true);

  while (fa.back() == 0) fa.pop_back();

  return fa;
}
//}}}
