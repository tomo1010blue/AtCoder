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
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector s(k, vector<ll>(n+1));
	rep(i, n) s[i%k][i+1] = a[i];
	rep(i, k) rep(j, n) s[i][j+1] += s[i][j];
	int q;
	cin >> q;
	while(q--) {
		int l, r;
		cin >> l >> r;
		--l;
		vector<ll> ns(k);
		rep(i, k) ns[i] = s[i][r]-s[i][l];
		sort(all(ns));
		if(ns[0] == ns.back()) cout << "Yes" << '\n';
		else cout << "No" << '\n';
	}
	return 0;
}