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
	int a, b;
	cin >> a >> b;
	--a; --b;
	int m;
	cin >> m;
	G g(n);
	rep(i, m) {
		int x, y;
		cin >> x >> y;
		--x; --y;
		g[x].pb(y);
		g[y].pb(x);
	}
	queue<int> q;
	vector<int> dst(n, -1);
	dst[a] = 0;
	q.push(a);
	vector<mint> ans(n);
	ans[a] = 1;
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		for(int u : g[v]) {
			if(dst[u] == -1) {
				dst[u] = dst[v] + 1;
				q.push(u);
			}
			if(dst[u] == dst[v] + 1) ans[u] += ans[v];
		}
	}
	cout << ans[b].val() << endl;
	return 0;
}