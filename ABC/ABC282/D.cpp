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

ll c2(ll n) {
	return n * (n - 1) / 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	G to(n);
	rep(i, m) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		to[u].pb(v);
		to[v].pb(u);
	}
	vector<int> c(n, -1);
	vector<int> cvs(2);
	auto dfs = [&](auto dfs, int v, int nc=0) -> bool {
    if (c[v] != -1) return c[v] == nc;
    c[v] = nc;
    cvs[nc]++;
    for (int u : to[v]) {
      if (!dfs(dfs,u,!nc)) return false;
    }
    return true;
  };
	ll ans = c2(n) - m;
	rep(i, n) {
		if(c[i] != -1) continue;
		cvs = vector<int>(2);
		if(!dfs(dfs, i)) {
			cout << 0 << endl;
			return 0;
		}
		for(int s : cvs) ans -= c2(s);
	}
	cout << ans << endl;
	return 0;
}