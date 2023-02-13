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
	int a, n;
	cin >> a >> n;
	const int MX = 1000000;
	vector<int> dist(MX, INF);
	queue<int> q;
	auto push = [&](int v, int d) {
		if(v >= MX) return;
		if(dist[v] != INF) return;
		dist[v] = d;
		q.push(v);
	};
	push(1, 0);
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		int d = dist[v];
		if(ll(v) * a < MX) push(v*a, d+1);
		if(v >= 10 && v % 10 != 0) {
			string s = to_string(v);
			int len = sz(s);
			rotate(s.begin(), s.begin()+(len-1), s.end());
			int u = stoi(s);
			push(u, d+1);
		}
	}
	if(dist[n] == INF) cout << -1 << endl;
	else cout << dist[n] << endl;
	return 0;
}