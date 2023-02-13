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
	int ax, ay, bx, by;
	cin >> ax >> ay >> bx >> by;
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	int cnt = 0;
	rep(i, n) {
		int a = (bx-ax) * (y[i]-ay) - (by-ay) * (x[i]-ax);
		int b = (bx-ax) * (y[(i+1)%n]-ay) - (by-ay) * (x[(i+1)%n]-ax);
		int c = (x[(i+1)%n]-x[i]) * (ay-y[i]) - (y[(i+1)%n]-y[i]) * (ax-x[i]);
		int d = (x[(i+1)%n]-x[i]) * (by-y[i]) - (y[(i+1)%n]-y[i]) * (bx-x[i]);	
		if(ll(a) * b < 0 && ll(c) * d < 0) ++cnt;
	}
	cout << cnt / 2 + 1 << endl;
	return 0;
}