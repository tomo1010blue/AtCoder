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

int f(string s) {
	vector<int> a(10);
	for(char c : s) a[c-'0']++;
	int res = 0;
	for(int i = 1; i <= 9; ++i) {
		int x = 1;
		rep(j, a[i]) x *= 10;
		res += x * i;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k;
	cin >> k;
	string s, t;
	cin >> s >> t;
	vector<int> c(10, k);
	c[0] = 0;
	rep(i, 4) c[s[i] - '0']--;
	rep(i, 4) c[t[i] - '0']--;
	ll cnt = 0;
	for(int a = 1; a <= 9; ++a) {
		for(int b = 1; b <= 9; ++b) {
			s[4] = '0' + a;
			t[4] = '0' + b;
			if(f(s) > f(t)) {
				if(a == b) cnt += (ll) c[a] * (c[a] - 1);
				else cnt += (ll) c[a] * c[b];
			}
		}
	}
	ll d = 0;
	rep(i, 10) d += c[i];
	ll tot = d * (d-1);
	double ans = (double) cnt / tot;
	cout << ans << endl;
	return 0;
}