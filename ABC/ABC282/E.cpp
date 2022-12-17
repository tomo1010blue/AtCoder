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
using P = pair<int, int>;
using Edge = pair<int, pair<int,int>>;
using G = vector<vector<int>>;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};
using mint = modint;
template<class T> inline bool chmin(T &a, T b){
	if(a > b){a = b; return true;}
	return false;
}
template<class T> inline bool chmax(T &a, T b){
	if(a < b){a = b; return true;}
	return false;
}

int f(int x, int y) {
	return (mint(x).pow(y) + mint(y).pow(x)).val();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	mint::set_mod(m);
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<Edge> edges;
	rep(i, n) rep(j, i) {
		edges.emplace_back(f(a[i], a[j]), P(i, j));
	}
	dsu uf(n);
	ll ans = 0;
	sort(rall(edges));
	for(auto [w, e] : edges) {
		auto [a, b] = e;
		if(uf.same(a, b)) continue;
		uf.merge(a, b);
		ans += w;
	}
	cout << ans << endl;
	return 0;
}