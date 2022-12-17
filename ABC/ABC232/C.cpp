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
	vector<vector<bool>> x(n, vector<bool>(n));
	vector<vector<bool>> y(n, vector<bool>(n));
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		x[a][b] = true;
		x[b][a] = true;
	}
	rep(i, m) {
		int c, d;
		cin >> c >> d;
		--c; --d;
		y[c][d] = true;
		y[d][c] = true;
	}
	vector<int> p(n);
	iota(all(p), 0);
	do {
		bool ok = true;
		rep(i, n) rep(j, n) if(x[i][j] != y[p[i]][p[j]]) ok = false;
		if(ok) {
			cout << "Yes" << endl;
			return 0;
		}
	} while (next_permutation(all(p)));
	cout << "No" << endl;
	return 0;
}