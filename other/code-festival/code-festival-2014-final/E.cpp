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
	vector<int> r(n);
	rep(i, n) cin >> r[i];
	vector dp(n, vector<int>(2));
	rep(i, n) {
		dp[i][0] = dp[i][1] = 1;
		rep(j, i) {
			if(r[j] < r[i]) chmax(dp[i][0], dp[j][1] + 1);
			if(r[j] > r[i]) chmax(dp[i][1], dp[j][0] + 1);
		}
	}
	int ans = max(dp[n-1][0], dp[n-1][1]);
	if(ans < 3) cout << 0 << endl;
	else cout << ans << endl;
	return 0;
}