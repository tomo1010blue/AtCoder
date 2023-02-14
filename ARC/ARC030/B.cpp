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
	int n, x;
	cin >> n >> x;
	--x;
	vector<int> h(n);
	rep(i, n) cin >> h[i];
	G g(n);
	rep(i, n-1) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].pb(b);
		g[b].pb(a);
	}
	vector<bool> used(n);
	used[x] = true;
	auto dfs = [&](auto f, int v, int p = -1) -> bool {
		if(h[v]) used[v] = true;
		for(auto u : g[v]) {
			if(u == p) continue;
			if(!used[v]) used[v] = f(f, u, v);
			else f(f, u, v);
		}
		if(used[v]) return true;
		return false;
	};
	dfs(dfs, x);
	int ans = -2;
	rep(i, n) if(used[i]) ans += 2;
	cout << ans << endl;
	return 0;
}