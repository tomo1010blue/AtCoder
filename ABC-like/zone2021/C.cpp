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
	int n;
	cin >> n;
	int m = 5;
	vector<vector<int>> a(n, vector<int>(m));
	rep(i, n) rep(j, m) cin >> a[i][j];
	int l = 0, r  = INF;
	while(l+1 < r) {
		int c = (l+r)/2;
		vector<int> s;
		rep(i, n) {
			int x = 0;
			rep(j, m) {
				if(a[i][j] >= c) x |= 1<<j;
			}
			s.pb(x);
		}
		sort(all(s));
		s.erase(unique(all(s)), s.end());
		bool ok = false;
		rep(i, sz(s))rep(j, i+1)rep(k, j+1) {
			if((s[i]|s[j]|s[k]) == (1<<m) - 1) ok = true;
		}
		if(ok) l = c; else r = c;
	}
	cout << l << endl;
	return 0;
}