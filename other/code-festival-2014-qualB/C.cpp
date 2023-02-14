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
	vector<string> s(3);
	rep(i, 3) cin >> s[i];
	int n = sz(s[0]);
	vector d(3, vector<int>(27));
	rep(i, 3) rep(j, n) d[i][s[i][j]-'A']++;
	int as = 0, bs = 0;
	rep(i, 26) {
		int x = d[2][i];
		int a = d[0][i], b = d[1][i];
		if(x > a + b) {
			cout << "NO" << endl;
			return 0;
		}
		as += max(0, x - b);
		bs += max(0, x - a);
	}
	if(as > n / 2 || bs > n / 2) cout << "NO" << endl;
	else cout << "YES" << endl;
	return 0;
}