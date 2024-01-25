// Sieve of Eratosthenes {{{
vector<int> sieve(const int MAX) {
  vector<bool> prime(MAX+1, true);
  prime[0] = prime[1] = false;

  vector<int> primes;
  for (int i = 2; i <= MAX; i++) {
    if (prime[i]) {
      primes.push_back(i);
      for (int j = 2*i; j <= MAX; j+=i) {
        prime[j] = false;
      }
    }
  }
  return primes;
}
//}}}

