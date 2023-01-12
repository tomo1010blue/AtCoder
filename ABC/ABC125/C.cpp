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

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}

int op(int a, int b) { return gcd(a, b);}

int e() { return 0;}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	segtree<int, op, e> seg(n);
	rep(i, n) {
		int a;
		cin >> a;
		seg.set(i, a);
	}
	int ans = 0;
	rep(i, n) {
		int t = seg.prod(0, i);
		t = gcd(t, seg.prod(i+1, n));
		chmax(ans, t);
	}
	cout << ans << endl;
	return 0;
}