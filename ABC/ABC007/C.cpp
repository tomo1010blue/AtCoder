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
	int r, c;
	cin >> r >> c;
	int sy, sx;
	cin >> sy >> sx;
	--sy; --sx;
	int gy, gx;
	cin >> gy >> gx;
	--gy; --gx;
	vector<string> g(r);
	rep(i, r) cin >> g[i];
	queue<int> q;
	q.push(sy*c+sx);
	vector<int> d(r*c, -1);
	d[sy*c+sx] = 0;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		int i = u / c;
		int j = u % c;
		rep(k, 4) {
			if(i+dy[k]<0 || i+dy[k]>=r || j+dx[k]<0 || j+dx[k]>=c) continue;
			if(g[i+dy[k]][j+dx[k]] == '#' || d[(i+dy[k])*c+j+dx[k]] != -1) continue;
			d[(i+dy[k])*c+j+dx[k]] = d[u] + 1;
			q.push((i+dy[k])*c+j+dx[k]);
		}
	}
	cout << d[gy*c+gx] << endl;
	return 0;
}