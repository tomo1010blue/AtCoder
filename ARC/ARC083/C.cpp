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
	int a, b, c, d, e, f;
	vector<int> w, s;
	cin >> a >> b >> c >> d >> e >> f;
	rep(i, f) rep(j, f) {
		int x = 100 * a * i + 100 * b * j;
		int y = c * i + d * j;
		if(x <= f) w.pb(x);
		if(y <= f) s.pb(y);
	}
	vector<pair<double, P>> con;
	for(int x : w) for(int y : s) {
		if(x + y > f) continue;
		if(100 * y > x * e) continue;
		double k = (double) 100 * y / (x + y);
		con.pb(make_pair(k, make_pair(x+y, y)));
	}
	sort(rall(con));
	cout << con[0].se.fi << " " << con[0].se.se << endl;
	return 0;
}