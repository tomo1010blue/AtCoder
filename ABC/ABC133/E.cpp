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
using mint = modint1000000007;
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
} comb(100005);

mint f(int n, int k) {
    if(n < 0) return 0;
    mint res = comb(n, k);
    res *= comb.fact[k];
    return res;
}

int k;
mint ans;
vector<int> to[100005];
void dfs(int v, int p = -1) {
    for(int u : to[v]) {
        if(u == p) continue;
        dfs(u, v);
    }
    int nk = (p == -1) ? k : k - 2;
    int c = (p == -1) ? sz(to[v]) + 1 : sz(to[v]) - 1;
    ans *= f(nk, c); 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n >> k;
    rep(i, n-1) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        to[a].pb(b);
        to[b].pb(a);
    }
    ans = 1;
    dfs(0);
    cout << ans.val() << endl;
    return 0;
}