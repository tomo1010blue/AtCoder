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
const ll INF = 10010010010010;
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
	int h, w;
	cin >> h >> w;
	vector<string> a(h);
	rep(i, h) cin >> a[i];
	int q;
	cin >> q;
	ll sa = 0, sb = 0;	
	rep(i, q) {
		ll a, b;
		cin >> a >> b;
		if((i+q)%2) {
			sa += a;
			sb += b;
		} else {
			sa -= a;
			sb -= b;
		}
	}
	if(q%2) {
		--sa;
		--sb;
	}
	sa += INF * h;
	sb += INF * w;
	sa %= h;
	sb %= w;
	vector<string> ans(h);
	rep(i, h) rep(j, w) ans[i] += 'A';
	rep(i, h) rep(j, w) {
		if(q%2) {
			int u = (sa - i + h) % h;
			int v = (sb - j + w) % w;
			ans[u][v] = a[i][j];
		} else {
			int u = (sa + i + h) % h;
			int v = (sb + j + w) % w;
			ans[u][v] = a[i][j];
		}
	}
	rep(i, h) cout << ans[i] << endl; 
	return 0;
}