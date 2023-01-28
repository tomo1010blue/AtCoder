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
const int dx[] = {-1, 1};
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
	vector<pair<string, int>> s(n);
	rep(i, n) {
		string t;
		cin >> t;
		s[i].fi = t;
		s[i].se = i;
	}
	sort(all(s));
	vector<int> ans(n);
	int pre = -1;
	rep(i, n-1) {
		int res = 0;
		int l = 0, r = min(sz(s[i].fi), sz(s[i+1].fi))+1, c;
		while(l+1<r) {
			c = (l+r) / 2;
			bool ok = true;
			repl(j, l, c) {
				if(s[i].fi[j] != s[i+1].fi[j]) {
					ok = false;
					break;
				}
			}
			if(ok) l = c;
			else r = c;
		}
		if(i == n-2) ans[s[n-1].se] = l;
		res = max(l, pre);
		pre = l;
		ans[s[i].se] = res;
	}
	rep(i, n) cout << ans[i] << endl;
	return 0;
}