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
using mint = modint998244353;
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
	int n, m, k;
	cin >> n >> m >> k;
	if(!k) {
		mint ans = mint(m).pow(n);
		cout << ans.val() << endl;
		return 0;
	}
	vector<mint> dp(m, 1);
	repl(i, 1, n) {
		vector<mint> p(m);
		swap(dp, p);
		vector<mint> s(m+1);
		rep(j, m) s[j+1] = s[j] + p[j];
		auto sum = [&] (int l, int r) -> mint {
			if(l > r) return 0;
			return s[r+1] - s[l];
		};
		rep(j, m) {
			dp[j] = sum(0, j-k) + sum(j+k, m-1);
		}
	}
	mint ans = 0;
	rep(i, m) ans += dp[i];
	cout << ans.val() << endl;
	return 0;
}