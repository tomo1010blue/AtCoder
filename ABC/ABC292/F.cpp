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

static const double pi = 3.141592653589793;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b;
	cin >> a >> b;
	if(a > b) swap(a, b);
	double ma = (double) a * 2 / (double) sqrt(3);
	if(b >= ma) {
		cout << setprecision(15) << ma << endl;
		return 0;
	}
	double dx = 1e-15;
	double ok = 0., ng = pi / 6, c = 0.;
	while(abs(ok-ng) > dx) {
		c = (ok + ng) / 2;
		double d = (double) cos(pi / 6 - c) * (double)a / (double) cos(c);
		if(d <= b) ok = c;
		else ng = c;
	}
	cout << setprecision(15) << (double) a / cos(c) << endl;
	return 0;
}