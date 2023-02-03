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
	int n;
	cin >> n;
	vector dp(n, vector<mint>(9));
	rep(i, 9) dp[0][i] = mint(1);
	rep(i, n-1) rep(j, 9) {
		if(j == 0) dp[i+1][j] = dp[i][j] + dp[i][j+1];
		else if(j == 8) dp[i+1][j] = dp[i][j-1] + dp[i][j];
		else dp[i+1][j] = dp[i][j-1] + dp[i][j] + dp[i][j+1];
	}
	mint ans = 0;
	rep(i, 9) ans += dp[n-1][i];
	cout << ans.val() << endl;
	return 0;
}