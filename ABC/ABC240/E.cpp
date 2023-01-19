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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	G to(n);
	rep(i, n-1) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		to[u].pb(v);
		to[v].pb(u);
	}
	vector<int> l(n), r(n);
	int x = 1;
	auto dfs = [&](auto f, int v, int p = -1) -> void {
		l[v] = x;
		for(int u : to[v]) {
			if(u == p) continue;
			f(f, u, v);
		}
		if(sz(to[v]) == 1 && p != -1) ++x;
		r[v] = x - 1;
	};
	dfs(dfs, 0);
	rep(i, n) cout << l[i] << " " << r[i] << endl;
	return 0;
}