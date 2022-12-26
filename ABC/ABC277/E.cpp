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

Struct Edge {
	int to, cost;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<Edge>> g(2*n);
	rep(i, m) {
		int u, v, a;
		cin >> u >> v >> a;
		--u; --v;
		if(a == 1) {
			g[u].pb((Edge){v,1});
			g[v].pb((Edge){u,1});
		} else {
			g[n+u].pb((Edge){n+v,1});
			g[n+v].pb((Edge){n+u,1});
		}
	}
	rep(i, k) {
		int v;
		cin >> v;
		--v;
		g[v].pb((Edge){n+v,0});
		g[n+v].pb((Edge){v,0});
	}
	vector<int> dist(2*n, INF);
	deque<P> q;
	dist[0] = 0;
	q.emplace_back(0, 0);
	while(q.size()) {
		auto [d, v] = q.front(); q.pop_front();
		if(dist[v] != d) continue;
		for(Edge e : g[v]) {
			int nd = d + e.cost;
			if(nd >= dist[e.to]) continue;
			dist[e.to] = nd;
			if(e.cost) q.emplace_back(nd, e.to);
			else q.emplace_front(nd, e.to);
		}
	}
	int ans = min(dist[n-1], dist[2*n-1]);
	if(ans == INF) ans = -1;
	cout << ans << endl;
	return 0;
}