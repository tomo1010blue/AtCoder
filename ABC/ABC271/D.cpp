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
	int n, s;
	cin >> n >> s;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];
	vector dp(n+1, vector<bool>(s+1));
	dp[0][0] = true;
	rep(i, n) rep(j, s+1) if(dp[i][j]) {
		if(j + a[i] <= s) dp[i+1][j+a[i]] = true;
		if(j + b[i] <= s) dp[i+1][j+b[i]] = true;
	}
	if(!dp[n][s]) {
		cout << "No" << endl;
		return 0;
	}
	string ans;
	for(int i = n-1; i >= 0; --i) {
		if(s-a[i] >= 0 && dp[i][s-a[i]]) {
			s -= a[i];
			ans += 'H';
		} else {
			s -= b[i];
			ans += 'T';
		}
	}
	reverse(all(ans));
	cout << "Yes" << endl;
	cout << ans << endl;
	return 0;
}