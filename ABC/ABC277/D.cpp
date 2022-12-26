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

ll s[200005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	map<int, int> mp;
	ll sum = 0;
	rep(i, n) {
		int a;
		cin >> a;
		mp[a]++;
		sum += (ll) a;
	}
	vector<P> v;
	for(auto p : mp) v.pb(p);
	int k = sz(v);
	if(k == m) {
		cout << 0 << endl;
		return 0;
	}
	int p;
	rep(i, k) {
		if(v[(i+1)%k].fi != (v[i].fi+1)%m) {
			p = i;
			break;
		}
	}
	rep(i, k) {
		int j = (p-i+k)%k;
		s[j] = sum;
		if(v[(j+1)%k].fi == (v[j].fi+1)%m) s[j] = s[(j+1)%k];
		s[j] -= (ll) v[j].fi * v[j].se;
	}
	ll ans = sum;
	rep(i, k) chmin(ans, s[i]);
	cout << ans << endl;
	return 0;
}