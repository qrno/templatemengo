// Non-prime Multiplicative Inverse {{{
int multinv(int A, int P) {
  auto [g, x, y] = ext_gcd(A, P);
  if (g != 1) return -1;
  x = (x % P + P) % P;
  return (x % P + P) % P;
}
//}}}
