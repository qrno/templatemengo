class HashedString {
	static const int M = (1LL << 61) - 1;
	static const int B;

	static V<int> pow;

	V<int> p_hash;

	__int128 mul(int a, int b) { return (__int128)a * b; }
	int mod_mul(int a, int b) { return mul(a, b) % M; }

public:
	explicit HashedString(string const& s) {
		while (size(pow) < size(s) + 1) pow.push_back(mod_mul(pow.back(), B));

    p_hash.resize(size(s) + 1);
		p_hash[0] = 0;
		for (int i = 0; i < size(s); i++) {
			p_hash[i + 1] = (mul(p_hash[i], B) + s[i]) % M;
		}
	}

	int get_hash(int start, int end) {
		int raw_val = p_hash[end + 1] - mod_mul(p_hash[start], pow[end - start + 1]);
		return (raw_val + M) % M;
	}
};
V<int> HashedString::pow = {1};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const int HashedString::B = uniform_int_distribution<int>(0, M - 1)(rng);
