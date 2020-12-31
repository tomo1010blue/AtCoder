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

struct combination {
    vector<mint> fact, ifact;
    combination(int n) : fact(n+1), ifact(n+1) {
        assert(n < 1000000007);
        fact[0] = 1;
        repl(i, 1, n+1) fact[i] = fact[i-1] * i;
        ifact[n] = fact[n].inv();
        for(int i = n; i >= 1; --i) ifact[i-1] = ifact[i] * i;
    }
    mint operator() (int n, int k) {
        if(k < 0 || k > n) return 0;
        return fact[n] * ifact[k] * ifact[n-k];
    }
    mint p(int n, int k) { return fact[n] * ifact[n-k];}
} c(200005);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    mint ans = 0;
    mint col = m;
    for(int x = n - 1; x >= 0; --x) {
        mint now = col;
        now *= c(n-1, x);
        if(x <= k) ans += now;
        col *= m - 1;
    }
    cout << ans.val() << endl;
    return 0;
}