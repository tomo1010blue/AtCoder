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
using mint = modint998244353;
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
	int n;
	string a, b;
	cin >> n >> a >> b;
	rep(i, n) {
		int ca = (int) (a[i] - '0');
		int cb = (int) (b[i] - '0');
		if(ca > cb) swap(a[i], b[i]);
	}
	mint ma = 0, mb = 0;
	mint d = mint(10).pow(n-1);
	rep(i, n) {
		int ca = (int) (a[i] - '0');
		int cb = (int) (b[i] - '0');
		ma += d * ca;
		mb += d * cb;
		d /= 10;
	}
	mint ans = ma * mb;
	cout << ans.val() << endl;
	return 0;
}