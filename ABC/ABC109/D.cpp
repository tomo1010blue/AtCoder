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
	int h, w;
	cin >> h >> w;
	vector g(h, vector<int>(w));
	rep(i, h) rep(j, w) {
		int a;
		cin >> a;
		g[i][j] = a % 2;
	}
	vector<vector<int>> ans;
	rep(i, h) {
		if(i == h-1) {
			rep(j, w-1) {
				if(g[i][j]) {
					g[i][j+1] ^= 1;
					vector<int> e = {i, j, i, j+1};
					ans.pb(e);
				}
			}
			continue;
		}
		rep(j, w) {
			if(g[i][j]) {
				g[i+1][j] ^= 1;
				vector<int> e = {i, j, i+1, j};
				ans.pb(e);
			}
		}
	}
	cout << sz(ans) << endl;
	for(auto x : ans) {
		cout << x[0]+1 << " " << x[1]+1 << " " << x[2]+1 << " " << x[3]+1 << endl;
	}
	return 0;
}