#include <bits/stdc++.h>
#include <atcoder/all>
#define fi first
#define se second
#define repl(i, l, r) for (int i = l; i < r; ++i)
#define rep(i, n) repl(i, 0, n)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;
using namespace atcoder;
using ll = long long;
using ld = long double;
using P = pair<double, double>;
using G = vector<vector<int>>;
using mint = modint1000000007;
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
    int to, id;
};

vector<vector<Edge>> g;
vector<int> ans;

void dfs(int v, int c = -1, int p = -1) {
    int k = 1;
    rep(i, g[v].size()) {
        int u = g[v][i].to, ei = g[v][i].id;
        if(u == p) continue;
        if(k == c) ++k;
        ans[ei] = k; 
        ++k;
        dfs(u, ans[ei], v);
    }
}

int main(void)
{
	int n;
    cin >> n;
    g.resize(n);
    ans = vector<int> (n);
    rep(i, n-1) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].pb((Edge){b, i});
        g[b].pb((Edge){a, i});
    }
    dfs(0);
    int mx = 0;
    rep(i, n) chmax(mx, int(g[i].size()));
    cout << mx << endl;
    rep(i, n-1) cout << ans[i] << endl;
    return 0;
}