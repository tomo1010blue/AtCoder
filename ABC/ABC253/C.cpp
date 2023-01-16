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
	int q;
	cin >> q;
	set<int> st;
	map<int, int> mp;
	while(q--) {
		int t;
		cin >> t;
		if(t == 1) {
			int x;
			cin >> x;
			st.insert(x);
			mp[x]++;
		}
		if(t == 2) {
			int x, c;
			cin >> x >> c;
			if(mp[x] > c) mp[x] -= c;
			else {
				st.erase(x);
				mp[x] = 0;
			}
		}
		if(t == 3) {
			auto it1 = st.begin();
			auto it2 = st.end();
			--it2;
			cout << *it2 - *it1 << endl;
		}
	}
	return 0;
}