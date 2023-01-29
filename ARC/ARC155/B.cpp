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
	int q, a, b;
	cin >> q;
	cin >> a >> b;
	set<int> st;
	st.insert(a+b);
	st.insert(a-b);
	while(q--) {
		int t;
		cin >> t >> a >> b;
		if(t == 1) {
			st.insert(a+b);
			st.insert(a-b);
		}
		else {
			auto it1 = st.lower_bound(a);
			int l = *it1;
			auto it2 = st.lower_bound(b);
			int r = *it2;
			if(it1 != it2) {
				cout << 0 << endl;
				continue;
			}
			if(it2 == st.end()) {
				--it2;
				r = *it2;
				cout << abs(a - r) << endl;
				continue;
			}
			int ans = abs(b - l);
			if(it2 != st.begin()) {
				--it2;
				r = *it2;
				int dr = abs(a - r);
				chmin(ans, dr);
			}
			cout << ans << endl;
		}
	}
	return 0;
}