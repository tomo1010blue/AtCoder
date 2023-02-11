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
	vector x(n, vector<ll>(3));
	rep(i, n) rep(j, 3) cin >> x[i][j];
	ll ma = -LINF;
	rep(i, 1<<3) {
		vector<ll> v;
		rep(j, n) {
			ll sum = 0;
			rep(k, 3) {
				if((i/(1<<k))%2 == 0) sum += x[j][k];
				else sum -= x[j][k];
			}
			v.pb(sum);
		}
		sort(all(v));
		reverse(all(v));
		ll ans = 0;
		rep(j, m) ans += v[j];
		chmax(ma, ans);
	}
	cout << ma << endl;
	return 0;
}