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
	int h, w;
	cin >> h >> w;
	vector<string> c(h);
	rep(i, h) cin >> c[i];
	dsu d(h*w);
	int s = 0;
	rep(i, h) rep(j, w) {
		if(c[i][j] == 'S') {
			s = i * w + j;
			continue;
		}
		if(c[i][j] == '#') continue;
		rep(k, 4) {
			if(i + dy[k] < 0 || i + dy[k] >= h || j + dx[k] < 0 || j + dx[k] >= w) continue;
			if(c[i+dy[k]][j+dx[k]] == '.' && !d.same(i*w+j, (i+dy[k])*w+j+dx[k])) d.merge(i*w+j, (i+dy[k])*w+j+dx[k]);
		}
	}
	vector<int> nei;
	rep(i, 4) {
		int sy = s / w;
		int sx = s % w;
		if(sy + dy[i] < 0 || sy + dy[i] >= h || sx + dx[i] < 0 || sx + dx[i] >= w) continue;
		nei.pb((sy+dy[i])*w+sx+dx[i]);
	}
	rep(i, sz(nei)) rep(j, i) {
		if(d.same(nei[i], nei[j])) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}