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
	int t;
	cin >> t;
	while(t--) {
		int r, g, b;
		cin >> r >> g >> b;
		int ans = -1;
		if(abs(g-b)%3 == 0) ans = max(g, b);
		if(abs(b-r)%3 == 0) {
			if(ans == -1) ans = max(b, r);
			else chmin(ans, max(b, r));	
		}
		if(abs(r-g)%3 == 0) {
			if(ans == -1) ans = max(r, g);
			else chmin(ans, max(r, g));
		}
		cout << ans << endl;
	}
	return 0;
}