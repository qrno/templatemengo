#include <bits/stdc++.h>
using namespace std;

// Template - Benq Edition (v0.1.0 - 2023-12-30) (comp.quirino.net) {{{
#define int long long
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

#define tcT template<class T
#define tcTU tcT, class U

#define V vector
tcT> using min_priority_queue = priority_queue<int, vector<int>, greater<int>>;
using str = string;

#define all(C) begin(C), end(C)
#define rall(C) rbegin(C), rend(C)
#define allb(C) begin(C), end(C), begin(C)
#define sz(C) ((int)size(C))

#define tp top()
#define ft front()
#define bk back()

#define ins insert
#define pb push_back
#define ff first
#define ss second
#define nemo ><>

#define iloop(I,L,R) for (int I = (L); I <= (R); I++)
#define loop(I,N) iloop(I,0,(N)-1)
#define rep(N) loop(_, N)
#define ipool(I,L,R) for (int I = (R); I >= (L); I--)
#define pool(I,N) ipool(I,0,(N)-1)

#define each(X,C) for(auto &X : (C))
#define apply(C,L) each(x,C) x=L;

#define cond(C, T, F) ((C) ? (T) : (F))
#define mem(C, X) memset((C), (X), sizeof(C))
#define ib(X, L, R) ((L) <= (X) && (X) <= (R))
#define L1(X...) [&](auto const& x){ return X; }
#define L2(X...) [&](auto const& x, auto const& y){ return X; }

#define testloop int T; cin >> T; while (T--)

tcTU> inline bool chmax(T &a, U const& b) { return (a < b ? a = b, 1 : 0); }
tcTU> inline bool chmin(T &a, U const& b) { return (a > b ? a = b, 1 : 0); }

int cdiv(int a, int b) { return a/b+((a^b)>0&&a%b); }
int fdiv(int a, int b) { return a/b-((a^b)<0&&a%b); }

#define tcTUU tcT, class ...U

inline namespace Helpers {
	//////////// is_iterable
	// https://stackoverflow.com/questions/13830158/check-if-a-variable-type-is-iterable
	// this gets used only when we can call begin() and end() on that type
	tcT, class = void> struct is_iterable : false_type {};
	tcT> struct is_iterable<T, void_t<decltype(begin(declval<T>())),
	                                  decltype(end(declval<T>()))
	                                 >
	                       > : true_type {};
	tcT> constexpr bool is_iterable_v = is_iterable<T>::value;

	//////////// is_readable
	tcT, class = void> struct is_readable : false_type {};
	tcT> struct is_readable<T,
	        typename std::enable_if_t<
	            is_same_v<decltype(cin >> declval<T&>()), istream&>
	        >
	    > : true_type {};
	tcT> constexpr bool is_readable_v = is_readable<T>::value;

	//////////// is_printable
	// // https://nafe.es/posts/2020-02-29-is-printable/
	tcT, class = void> struct is_printable : false_type {};
	tcT> struct is_printable<T,
	        typename std::enable_if_t<
	            is_same_v<decltype(cout << declval<T>()), ostream&>
	        >
	    > : true_type {};
	tcT> constexpr bool is_printable_v = is_printable<T>::value;
}

inline namespace Input {
	tcT> constexpr bool needs_input_v = !is_readable_v<T> && is_iterable_v<T>;
	tcTUU> void in(T& t, U&... u);
	tcTU> void in(pair<T,U>& p); // pairs

	// re: read
	tcT> typename enable_if<is_readable_v<T>,void>::type in(T& x) { cin >> x; } // default
	tcT> void in(complex<T>& c) { T a,b; in(a,b); c = {a,b}; } // complex
	tcT> typename enable_if<needs_input_v<T>,void>::type in(T& i); // ex. vectors, arrays
	tcTU> void in(pair<T,U>& p) { in(p.f,p.s); }
	tcT> typename enable_if<needs_input_v<T>,void>::type in(T& i) {
		each(x,i) in(x); }
	tcTUU> void in(T& t, U&... u) { in(t); in(u...); } // read multiple

	// rv: resize and read vectors
	void rv(size_t) {}
	tcTUU> void rv(size_t N, V<T>& t, U&... u);
	template<class...U> void rv(size_t, size_t N2, U&... u);
	tcTUU> void rv(size_t N, V<T>& t, U&... u) {
		t.rsz(N); in(t);
		rv(N,u...); }
	template<class...U> void rv(size_t, size_t N2, U&... u) {
		rv(N2,u...); }

	// dumb shortcuts to read in ints
	void decrement() {} // subtract one from each
	tcTUU> void decrement(T& t, U&... u) { --t; decrement(u...); }
	#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);
	#define int1(...) ints(__VA_ARGS__); decrement(__VA_ARGS__);
}

inline namespace ToString {
	tcT> constexpr bool needs_output_v = !is_printable_v<T> && is_iterable_v<T>;

	// ts: string representation to print
	tcT> typename enable_if<is_printable_v<T>,str>::type ts(T v) {
		stringstream ss; ss << fixed << setprecision(15) << v;
		return ss.str(); } // default
	tcT> str bit_vec(T t) { // bit vector to string
		str res = "{"; loop (i,sz(t)) res += ts(t[i]);
		res += "}"; return res; }
	str ts(V<bool> const& v) { return bit_vec(v); }
	template<size_t SZ> str ts(bitset<SZ> const& b) { return bit_vec(b); } // bit vector
	tcTU> str ts(pair<T,U> p); // pairs
	tcT> typename enable_if<needs_output_v<T>,str>::type ts(T v); // vectors, arrays
	tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
	tcT> typename enable_if<is_iterable_v<T>,str>::type ts_sep(T v, str sep) {
		// convert container to string w/ separator sep
		bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += sep;
			fst = 0; res += ts(x);
		}
		return res;
	}
	tcT> typename enable_if<needs_output_v<T>,str>::type ts(T v) {
		return "{"+ts_sep(v,", ")+"}"; }

	// for nested DS
	template<int, class T> typename enable_if<!needs_output_v<T>, V<str>>::type
	  ts_lev(const T& v) { return {ts(v)}; }
	template<int lev, class T> typename enable_if<needs_output_v<T>, V<str>>::type
	  ts_lev(const T& v) {
		if (lev == 0 || !sz(v)) return {ts(v)};
		V<str> res;
		for (const auto& t: v) {
			if (sz(res)) res.bk += ",";
			V<str> tmp = ts_lev<lev-1>(t);
			res.ins(end(res),all(tmp));
		}
		loop (i,sz(res)) {
			str bef = " "; if (i == 0) bef = "{";
			res[i] = bef+res[i];
		}
		res.bk += "}";
		return res;
	}
}

inline namespace Output {
	template<class T> void pr_sep(ostream& os, str, const T& t) { os << ts(t); }
	template<class T, class... U> void pr_sep(ostream& os, str sep, const T& t, const U&... u) {
		pr_sep(os,sep,t); os << sep; pr_sep(os,sep,u...); }
	// print w/ no spaces
	template<class ...T> void pr(const T&... t) { pr_sep(cout,"",t...); } 
	// print w/ spaces, end with newline
	void ps() { cout << "\n"; }
	template<class ...T> void ps(const T&... t) { pr_sep(cout," ",t...); ps(); } 
	// debug to cerr
	template<class ...T> void dbg_out(const T&... t) {
		pr_sep(cerr," | ",t...); cerr << endl; }
	void loc_info(int line, str const& names) {
		cerr << "Line(" << line << ") -> [" << names << "]: "; }
	template<int lev, class T> void dbgl_out(const T& t) {
		cerr << "\n\n" << ts_sep(ts_lev<lev>(t),"\n") << "\n" << endl; }
	#ifdef LOCAL
		#define dbg(...) loc_info(__LINE__,#__VA_ARGS__), dbg_out(__VA_ARGS__)
		#define dbgl(lev,x) loc_info(__LINE__,#x), dbgl_out<lev>(x)
	#else // don't actually submit with this
		#define dbg(...)
		#define dbgl(lev,x)
	#endif

	// https://stackoverflow.com/questions/47980498/accurate-c-c-clock-on-a-multi-core-processor-with-auto-overclock?noredirect=1&lq=1
	const auto beg = std::chrono::high_resolution_clock::now();
	void dbg_time() {
		auto duration = chrono::duration<double>(
			std::chrono::high_resolution_clock::now() - beg);
		dbg(duration.count());
	}
}
// }}}

signed main() {
  fastio;

}

