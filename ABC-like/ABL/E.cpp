#include <bits/stdc++.h>
#include <atcoder/all>
#define fi first
#define se second
#define repl(i, l, r) for (int i = l; i < r; ++i)
#define rep(i, r) repl(i, 0, r)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(x) ((int) (x).size())
using namespace std;
using namespace atcoder;
using ll = long long;
using ld = long double;
using mint = modint998244353;
using P = pair<int, int>;
using G = vector<vector<int>>;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};
template<class T> inline bool chmin(T &a, T b){
    if(a > b){a = b; return true;}
    return false;
}
template<class T> inline bool chmax(T &a, T b){
    if(a < b){a = b; return true;}
    return false;
}

struct S {
    mint x, w;
    S(mint x = 0, mint w = 1) : x(x), w(w) {}
};

S op(S a, S b) {
    return S(a.x * b.w + b.x, a.w * b.w);
}

S e() { return S();}

S mapping(int f, S a) {
    if(f == 0) return a;
    return S((a.w - 1) / 9 * f, a.w);
} 

int composition(int f, int g) {
    if(f == 0) return g;
    return f;
}

int id() { return 0;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    lazy_segtree<S, op, e, int, mapping, composition, id> t(n);
    rep(i, n) t.set(i, S(1, 10));
    rep(qi, q) {
        int l, r, d;
        cin >> l >> r >> d;
        --l;
        t.apply(l, r, d);
        S ans = t.all_prod();
        cout << ans.x.val() << '\n';
    }
    return 0;
}