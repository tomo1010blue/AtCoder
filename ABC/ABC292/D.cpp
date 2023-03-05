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
	if(n != m) {
		cout << "No" << endl;
		return 0;
	}
	dsu d(n);
	map<int, int> mp;
	rep(i, m) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		if(d.same(u, v)) mp[d.leader(u)]++;
		else {
			int t = mp[d.leader(u)];
			mp[d.leader(u)] += mp[d.leader(v)]+1;
			mp[d.leader(v)] += t+1;
		}
		d.merge(u, v);
	}
	G g = d.groups();
	for(auto a : g) {
		if(sz(a) != mp[d.leader(a[0])]) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}