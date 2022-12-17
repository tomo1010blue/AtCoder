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
	int h, w, n;
	cin >> h >> w >> n;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];
	vector<int> a_c(n), b_c(n);
	a_c = a;
	b_c = b;
	sort(all(a_c));
	sort(all(b_c));
	a_c.erase(unique(all(a_c)), a_c.end());
	b_c.erase(unique(all(b_c)), b_c.end());
	vector<int> a_r(n), b_r(n);
	rep(i, n) {
		a_r[i] = lower_bound(all(a_c), a[i]) - a_c.begin() + 1;
		b_r[i] = lower_bound(all(b_c), b[i]) - b_c.begin() + 1;
	}
	rep(i, n) cout << a_r[i] << " " << b_r[i] << endl;
	return 0;
}