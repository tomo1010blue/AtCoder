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
	int to, w;
	Edge(int to, int w) : to(to), w(w) {}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int s, t;
	cin >> s >> t;
	--s; --t;
	vector g(n, vector<Edge>());
	rep(i, m) {
		int x, y, d;
		cin >> x >> y >> d;
		--x; --y;
		g[x].eb(y, d);
		g[y].eb(x, d);
	}
	priority_queue<P, vector<P>, greater<P>> q;
	vector<int> dsts(n, INF);
	dsts[s] = 0;
	q.push(P(0, s));
	while(!q.empty()) {
		auto [d, u] = q.top(); q.pop();
		if(dsts[u] != d) continue;
		for(auto [v, w] : g[u]) if(chmin(dsts[v], dsts[u]+w)) q.push(P(dsts[v], v));
	}
	vector<int> dstt(n, INF);
	dstt[t] = 0;
	q.push(P(0, t));
	while(!q.empty()) {
		auto [d, u] = q.top(); q.pop();
		if(dstt[u] != d) continue;
		for(auto [v, w] : g[u]) if(chmin(dstt[v], dstt[u]+w)) q.push(P(dstt[v], v));
	}
	rep(i, n) if(dsts[i] == dstt[i] && dsts[i] != INF) {
		cout << i+1 << endl;
		return 0;
	}
	cout << -1 << endl;
	return 0;
}