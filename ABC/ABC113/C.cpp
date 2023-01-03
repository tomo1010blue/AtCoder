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
	map<int, vector<P>> mp;
	rep(i, m) {
		int p, y;
		cin >> p >> y;
		mp[p].eb(y, i);
	}
	for(auto v : mp) sort(all(mp[v.fi]));
	vector<string> ans(m);
	for(auto v : mp) {
		int tmp = 1;
		for(auto u : v.se) {
			string t = "";
			string k = to_string(v.fi);
			string j = to_string(tmp);
			rep(i, 6-sz(k)) t += "0";
			t += k;
			rep(i, 6-sz(j)) t += "0";
			t += j;
			ans[u.se] = t;
			++tmp;
		}
	}
	rep(i, m) cout << ans[i] << endl;
	return 0;
}