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
const int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
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
	G a(n, vector<int>(n));
	rep(i, n) {
		ll A;
		cin >> A;
		rep(j, n) {
			a[i][j] = (int) (A / (ll) pow(10, n-j-1));
			A %= (ll) pow(10, n-j-1);
		}
	}
	ll ans = 0;
	rep(i, n) rep(j, n) {
		rep(k, 8) {
			ll sum = 0;
			rep(l, n) sum += (ll) a[(i+dx[k]*l+n)%n][(j+dy[k]*l+n)%n] * (ll) pow(10, n-l-1);
			chmax(ans, sum);
		}
	}
	cout << ans << endl;
	return 0;
}