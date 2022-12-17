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
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
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
	int n, x;
	cin >> n >> x;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];
	ll ans = LINF;
	ll sum = 0;
	rep(i, n) {
		if(i + 1 > x) break;
		sum += a[i] + b[i];
		chmin(ans, sum + (ll) b[i] * (x - i - 1));
	}
	cout << ans << endl;
	return 0;
}