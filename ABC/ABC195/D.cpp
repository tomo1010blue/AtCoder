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
	int n, m, q;
	cin >> n >> m >> q;
	vector<int> w(n), v(n);
	rep(i, n) cin >> w[i] >> v[i];
	vector<int> x(m);
	rep(i, m) cin >> x[i];
	while(q--) {
		int l, r;
		cin >> l >> r;
		--l; --r;
		int ans = 0;
		vector<int> as;
		rep(i, m) if(i < l || r < i) as.pb(x[i]);
		sort(all(as));
		vector<bool> used(n);
		for (int a : as) {
			P best(-1, -1);
			rep(i, n) {
				if(used[i]) continue;
				if(w[i] > a) continue;
				best = max(best, P(v[i], i));
			}
			if(best.se == -1) continue;
			used[best.se] = true;
			ans += v[best.se];
		}
		cout << ans << endl;
	}
	return 0;
}