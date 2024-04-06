// Debug {{{
#define var(x) "[", #x, " ", x, "] "
template<typename ...A> void db(A const&... a) { ((cout << (a)), ...); cout << endl; }
//}}}
