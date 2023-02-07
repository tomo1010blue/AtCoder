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

int in() {
	double x;
	cin >> x;
	x *= 10000;
	return round(x);
}

bool ok(ll dx, ll dy, ll z) {
	return dx * dx + dy * dy <= z * z;
}

ll f(ll x, ll y, ll z, ll lim) {
	int l = 0, r = 1;
	ll res = 0;
	for(int i = (int)1e9 + 50000; i >= lim; i -= 10000) {
		while(ok(x-l*10000, i-y, z)) --l;
		while(ok(r*10000-x, i-y, z)) ++r;
		res += r-l-1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll x = in();
	ll y = in();
	ll z = in();
	x %= 10000;
	y %= 10000;
	ll ans = f(x, y, z, 10000);
	ans += f(x, -y, z, 0);
	cout << ans << endl;
	return 0;
}