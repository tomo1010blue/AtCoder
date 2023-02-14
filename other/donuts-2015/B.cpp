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
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<int> b(m);
	vector<bitset<32>> combo(m);
	rep(i, m) {
		int c;
		cin >> b[i] >> c;
		while(c--) {
			int x;
			cin >> x;
			--x;
			combo[i][x] = true;
		}
	}
	int ans = 0;
	rep(i, 1<<n) {
		bitset<32> bs(i);
		if(bs.count() != 9) continue;
		int sum = 0;
		rep(j, n) if(bs[j]) sum += a[j];
		rep(j, m) if((bs & combo[j]).count() >= 3) sum += b[j];
		chmax(ans, sum);
	}
	cout << ans << endl;
	return 0;
}