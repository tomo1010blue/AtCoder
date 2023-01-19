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
	int n, x, y, z;
	cin >> n >> x >> y >> z;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	vector<bool> ok(n);
	auto f = [&](vector<int> d, int num) {
		vector<int> p;
		rep(i, n) if(!ok[i]) p.pb(i);
		auto cmp = [&](int i, int j) {
			if(d[i] != d[j]) return d[i] > d[j];
			return i < j;
		};
		sort(all(p), cmp);
		rep(i, num) ok[p[i]] = true;
	};
	f(a, x);
	f(b, y);
	rep(i, n) a[i] += b[i];
	f(a, z);
	rep(i, n) if(ok[i]) cout << i+1 << endl;
	return 0;
}