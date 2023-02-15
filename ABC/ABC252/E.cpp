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
using P = pair<ll, int>;
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
	int to, cost, id;
	Edge(int to, int cost, int id) : to(to), cost(cost), id(id) {}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector g(n, vector<Edge>());
	rep(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		--a; --b;
		g[a].eb(b, c, i+1);
		g[b].eb(a, c, i+1);
	}
	priority_queue<P, vector<P>, greater<P>> q;
	vector<ll> dst(n, LINF);
	vector<int> from(n, -1);
	dst[0] = 0;
	q.push(P(0, 0));
	while(!q.empty()) {
		auto [d, v] = q.top(); q.pop();
		if(dst[v] != d) continue;
		for(auto [u, cost, id] : g[v]) if(chmin(dst[u], dst[v]+cost)) {
			from[u] = id;
			q.push(P(dst[u], u));
		}
	}
	rep(i, n-1) cout << from[i+1] << endl;
	return 0;
}