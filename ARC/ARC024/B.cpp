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
	vector<int> c(n);
	rep(i, n) cin >> c[i];
	int sum = 0;
	rep(i, n) if(c[i]) ++sum;
	if(sum == 0 || sum == n) {
		cout << -1 << endl;
		return 0;
	}
	vector<int> cnt;
	int num = 1;
	rep(i, n-1) {
		if(c[i] == c[i+1]) ++num;
		else {
			cnt.pb(num);
			num = 1;
		}
	}
	if(c[0] == c[n-1]) cnt[0] += num;
	else cnt.pb(num);
	int ans = 0;
	for(auto x : cnt) chmax(ans, (x + 1) / 2 - 1);
	cout << ans+1 << endl;
	return 0;
}