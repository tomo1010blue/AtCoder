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

int n, n2, ans;
vector<vector<int>> a;

void dfs(vector<bool> s, int x) {
	int si = -1;
	rep(i, n2) if(!s[i]) {
		si = i;
		break;
	}
	if(si == -1) {
		chmax(ans, x);
		return;
	}
	s[si] = true;
	rep(i, n2) if(!s[i] && si != i) {
		s[i] = true;
		dfs(s, x^a[si][i]);
		s[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	n2 = 2 * n;
	a = vector<vector<int>> (n2, vector<int>(n2));
	rep(i, n2) {
		for(int j = i+1; j < n2; j++){
			cin >> a[i][j];
			a[j][i] = a[i][j];
		}
	}
	vector<bool> s(n2);
	dfs(s, 0);
	cout << ans << endl;
	return 0;
}