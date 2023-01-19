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
	int n, k;
	cin >> n >> k;
	vector<int> under(n, -1);
	vector<int> pile(n, 0);
	set<int> st;
	vector<int> ans(n, -1);
	rep(i, n) {
		int p;
		cin >> p;
		auto it = st.upper_bound(p);
		if(it == st.end()) {
			pile[p-1] = 1;
			st.insert(p);
		} else {
			under[p-1] = (*it);
			pile[p-1] = pile[(*it)-1] + 1;
			st.erase(it);
			st.insert(p);
		}
		if(pile[p-1] == k) {
			st.erase(p);
			int x = p;
			rep(j, k) {
				ans[x-1] = i+1;
				x = under[x-1];
			}
		}
	}
	rep(i, n) cout << ans[i] << endl;
	return 0;
}