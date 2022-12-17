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
	ll n, k;
	cin >> n >> k;
	ll check = k;
	while(k % 10 == 0) k /= 10;
	ll kv = 0;
	ll kc = k;
	while(kc != 0) {
		kv *= (ll) 10;
		kv += kc % 10;
		kc /= 10;
	}
	if(k != check && kv != check) {
		cout << 0 << endl;
		return 0;
	}
	int ans = 0;
	if(k == kv) {
		while(k <= n) {
			++ans;
			k *= (ll) 10;
		}
		cout << ans << endl;
		return 0;
	} else {
		while(kv <= n) {
			++ans;
			kv *= (ll) 10;
		}
		while(k <= n) {
			++ans;
			k *= (ll) 10;
		}
		cout << ans << endl;
		return 0;
	}
	return 0;
}