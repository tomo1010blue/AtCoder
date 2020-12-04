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

struct Edge {
    int to;
    ll cost;
};

const int limit = 100005;
vector<Edge> tree[limit];
ll depth[limit];

void dfs(int v, int p, ll d) {
    depth[v] = d;
    for(auto &e : tree[v]) {
        if(e.to == p) continue;
        dfs(e.to, v, d + e.cost);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    rep(i, n-1) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        tree[a].pb({b, c});
        tree[b].pb({a, c});
    }
    int q, k;
    cin >> q >> k;
    --k;
    dfs(k, -1, 0);
    rep(i, q) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        cout << depth[x] + depth[y] << '\n';
    }
    return 0;
}