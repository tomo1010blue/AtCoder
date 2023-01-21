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
	vector<P> a(n), b(n), c(n);
	rep(i, n) {
		int x, y;
		cin >> x >> y;
		a[i] = P(x, i);
		b[i] = P(y, i);
		c[i] = P(x+y, i);
	}
	sort(all(a));
	sort(all(b));
	sort(all(c));
	int ans = 0;
	if(a[0].se != b[0].se) ans = max(a[0].fi, b[0].fi);
	else {
		ans = max(a[1].fi, b[0].fi);
		chmin(ans, max(a[0].fi, b[1].fi));
	}
	chmin(ans, c[0].fi);
	cout << ans << endl;
	return 0;
}