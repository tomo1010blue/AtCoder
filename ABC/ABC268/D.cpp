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
	int n, m;
	cin >> n >> m;
	vector<string> S(n);
	rep(i, n) cin >> S[i];
	set<string> ts;
	rep(i, m) {
		string t;
		cin >> t;
		ts.insert(t);
	}
	int max_u = 16 - (n - 1);
	rep(i, n) max_u -= sz(S[i]);
	vector<bool> used(n);
	auto dfs = [&](auto f, int i, string s, int u) -> bool {
		if(i == n) {
			if(sz(s) < 3) return false;
			if(ts.count(s)) return false;
			cout << s << endl;
			return true;
		}
		if(u) if(f(f, i, s+'_', u-1)) return true;
		rep(j, n) if(!used[j]) {
			used[j] = true;
			if(f(f, i+1, s+'_'+S[j], u)) return true;
			used[j] = false;
		}
		return false;
	};
	rep(i, n) {
		used[i] = true;
		if(dfs(dfs, 1, S[i], max_u)) return 0;
		used[i] = false;
	}
	cout << -1 << endl;
	return 0;
}