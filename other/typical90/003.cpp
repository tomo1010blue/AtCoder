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
	G g(n);
	rep(i, n-1) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		g[a].pb(b);
		g[b].pb(a);
	}
	queue<int> q;
	q.push(0);
	vector<int> dist(n, -1);
	dist[0] = 0;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(auto v : g[u]) {
			if(dist[v] != -1) continue;
			dist[v] = dist[u] + 1;
			q.push(v);
		}
	}
	int end = max_element(all(dist)) - dist.begin();
	q.push(end);
	vector<int> dist2(n, -1);
	dist2[end] = 0;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(auto v : g[u]) {
			if(dist2[v] != -1) continue;
			dist2[v] = dist2[u] + 1;
			q.push(v);
		}
	}
	int ans = *max_element(all(dist2)) + 1;
	cout << ans << endl;
	return 0;
}