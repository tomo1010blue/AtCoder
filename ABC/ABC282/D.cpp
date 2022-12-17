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

vector <int> g[200005];
int n;
int color[200005];

bool dfs(int v, int c) {
	color[v] = c;
	rep(i, sz(g[v])) {
		if(color[g[v][i]] == c) return false;
		if(color[g[v][i]] == 0 && !dfs(g[v][i], -c)) return false;
	}
	return true;
}

struct UnionFind {
	vector<int> d;
	UnionFind(int n=0): d(n,-1) {}
	int find(int x) {
		if (d[x] < 0) return x;
		return d[x] = find(d[x]);
	}
	bool unite(int x, int y) {
		x = find(x); y = find(y);
		if (x == y) return false;
		if (d[x] > d[y]) swap(x,y);
		d[x] += d[y];
		d[y] = x;
		return true;
	}
	bool same(int x, int y) { return find(x) == find(y);}
	int size(int x) { return -d[find(x)];}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m;
	cin >> n >> m;
	rep(i, m) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		g[u].pb(v);
		g[v].pb(u);
	}

	return 0;
}