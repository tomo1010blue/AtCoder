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
	vector cost(n, vector<int>(n));
	rep(i, n) rep(j, n) cin >> cost[i][j];
	int n2 = 1<<n;
	vector dp(n2, vector<ll>(n, LINF));
	repl(i, 1, n) dp[1<<i][i] = cost[0][i];
	dp[0][0] = 0;
	rep(i, n2) rep(j, n) {
		if(~i>>j&1) continue;
		rep(k, n) {
			if(i>>k&1) continue;
			chmin(dp[i|1<<k][k], dp[i][j]+cost[j][k]);
		}
	}
	cout << dp[n2-1][0] << endl;
	return 0;
}