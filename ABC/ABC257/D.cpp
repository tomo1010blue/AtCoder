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
	vector<int> x(n), y(n), p(n);
	rep(i, n) cin >> x[i] >> y[i] >> p[i];
	ll wa = 0, ac = 4e9;
	while(abs(wa - ac) > 1) {
		ll wj = (wa + ac) / 2;
		bool judge = [&] {
			vector d(n, vector<int>(n));
			rep(i, n) rep(j, n) {
				ll dist = (ll) abs(x[i] - x[j]) + abs(y[i] - y[j]);
				if(wj * p[i] >= dist) d[i][j] = 1;
			}
			rep(k, n) rep(i, n) rep(j, n) d[i][j] |= d[i][k]&d[k][j];
			bool res = false;
			rep(i, n) {
				bool ok = true;
				rep(j, n) if(d[i][j] != 1) ok = false;
				if(ok) return true;
			}
			return false;
		}();
		if(judge) ac = wj; else wa = wj;
	}
	cout << ac << endl;
	return 0;
}