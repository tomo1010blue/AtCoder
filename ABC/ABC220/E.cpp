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
	int n, d;
	cin >> n >> d;
	vector<mint> f(n+1), g(n+1);
	vector<mint> two(n+1);
	two[0] = 1;
	rep(i, n) two[i+1] = two[i] * 2;
	repl(i, 1, n+1) {
		int l = i - 1, r = d - l;
		mint leaf = 0;
		if(0 <= r && r <= i - 1) {
			leaf = two[max(l-1, 0)]*two[max(r-1, 0)];
			if(l != r) leaf *= 2;
		}
		g[i] = g[i-1] + leaf;
	}
	repl(i, 1, n+1) f[i] = f[i-1] * 2 + g[i];
	cout << (f[n]*2).val() << endl;
	return 0;
}