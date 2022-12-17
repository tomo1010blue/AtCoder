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
	modint::set_mod(m);
	modint x[100005][10];
	int ans_d = -1;
	int ans_n = -1;
	rep(i, 9) x[1][i+1] = modint(i+1);
	rep(i, n-1) rep(j, 9) x[i+2][j+1] = 10 * x[i+1][j+1] + modint(j+1);
	bool ok = true;
	for(int i = n; i > 0; --i) {
		for(int j = 9; j > 0; --j) {
			if(x[i][j].val() == 0) {
				ans_d = i;
				ans_n = j;
				ok = false;
				break;
			}
		}
		if(!ok) break;
	}
	if(ans_d == -1) {
		cout << -1 << endl;
		return 0;
	}
	string ans = "";
	while(ans_d--) {
		char c = char(ans_n + '0');
		ans.pb(c);
	}
	cout << ans << endl;
	return 0;
}