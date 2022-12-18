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
using P = pair<ll, ll>;
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
	vector<ll> a(n+1);
	rep(i, n+1) cin >> a[i];
	vector<P> p(n+1);
	for(int i = n; i >= 0; --i) {
		if(i == n) {
			p[i].fi = a[i];
			p[i].se = a[i];
			continue;
		}
		p[i].fi = (p[i+1].fi + 1) / 2 + a[i];
		p[i].se = p[i+1].se + a[i];
	}
	if(p[0].fi > 1) {
		cout << -1 << endl;
		return 0;
	}
	ll ans = 1;
	vector<ll> v(n+1);
	v[0] = 1;
	repl(i, 1, n+1) {
		v[i] = min(p[i].se, 2*(v[i-1]-a[i-1]));
		ans += v[i];
	}
	cout << ans << endl;
	return 0;
}