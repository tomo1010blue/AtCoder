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
	vector<int> a(m), b(m);
	rep(i, m) cin >> a[i] >> b[i];
	int k;
	cin >> k;
	vector<int> c(k), d(k);
	rep(i, k) cin >> c[i] >> d[i];
	int ans = 0;
	for(int i = 0; i < (1<<k); ++i) {
		vector<bool> ball(n, false);
		int num = 0;
		rep(j, k) {
			if(i & (1<<j)) ball[c[j]] = true;
			else ball[d[j]] = true;
		}
		rep(j, m) if(ball[a[j]] && ball[b[j]]) ++num;
		chmax(ans, num);
	}
	cout << ans << endl;
	return 0;
}