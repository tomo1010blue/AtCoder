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
	vector<int> sum1(n+1), sum2(n+1);
	sum1[0] = 0;
	sum2[0] = 0;
	rep(i, n) {
		int c, p;
		cin >> c >> p;
		if(c == 1) {
			sum1[i+1] = sum1[i] + p;
			sum2[i+1] = sum2[i];
		} else {
			sum1[i+1] = sum1[i];
			sum2[i+1] = sum2[i] + p;
		}
	}
	int q;
	cin >> q;
	while(q--) {
		int l, r;
		cin >> l >> r;
		cout << sum1[r] - sum1[l-1] << " " << sum2[r] - sum2[l-1] << endl;
	}
	return 0;
}