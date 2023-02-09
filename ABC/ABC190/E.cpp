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
	G g(n);
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].pb(b);
		g[b].pb(a);
	}
	int k;
	cin >> k;
	vector<int> c(k);
	rep(i, k) {
		cin >> c[i];
		--c[i];
	}
	vector dist(k, vector<int> (k));
	rep(i, k) {
		queue<int> q;
		vector<int> dst(n, -1);
		dst[c[i]] = 0;
		q.push(c[i]);
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			for(auto v : g[u]) {
				if(dst[v] != -1) continue;
				dst[v] = dst[u] + 1;
				q.push(v);
			}
		}
		rep(j, i) {
			if(dst[c[j]] == -1) {
				cout << -1 << endl;
				return 0;
			}
			dist[i][j] = dst[c[j]];
			dist[j][i] = dst[c[j]];
		}
	}
	int k2 = 1 << k;
	vector dp(k2, vector<int> (k, INF));
	rep(i, k) dp[1<<i][i] = 1;
	rep(s, k2) rep(i, k) {
		if(~s>>i&1) continue;
		rep(j, k) {
			if(s>>j&1) continue;
			chmin(dp[s|1<<j][j], dp[s][i]+dist[i][j]);
		}
	}
	int ans = INF;
	rep(i, k) chmin(ans, dp[k2-1][i]);
	cout << ans << endl;
	return 0;
}