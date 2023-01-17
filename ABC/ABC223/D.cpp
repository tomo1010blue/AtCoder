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
	int n, m;
	cin >> n >> m;
	vector to(n, vector<int>());
	vector<int> deg(n);
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		to[a].pb(b);
		deg[b]++;
	}
	priority_queue<int, vector<int>, greater<int>> q;
	rep(i, n) if(!deg[i]) q.push(i);
	vector<int> ans;
	while(!q.empty()) {
		int v = q.top(); q.pop();
		ans.pb(v);
		for(int u : to[v]) {
			--deg[u];
			if(!deg[u]) q.push(u);
		}
	}
	if(sz(ans) != n) cout << -1 << endl;
	else for(int v : ans) cout << v + 1 << endl;
	return 0;
}